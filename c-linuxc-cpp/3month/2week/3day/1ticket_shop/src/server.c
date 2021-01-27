#include "head.h"

typedef struct cl_node
{
    char msg[256]; // 要发送的消息
    char ip[20];
    int so_fd; // 未连接的套接字文件描述符
    int confd; // 连接的套接字文件描述符
    pthread_mutex_t m;
    struct list_head head; // 内核链表

    struct flightNode *flist;
    struct userNode *ulist;

} c_node, *cp_list;

void *read_msg(void *arg);
void handler(void *arg);
int init_sock(const char *str_port);
int add_thread(int so_fd, cp_list c_list);
int regist_s(char *buf, cp_list c_list);
int login(char *buf, cp_list c_list);

int main(int argc, char const *argv[]) // /.server.out 端口号
{

    //大结构体链表起始
    u_list list_u = malloc(sizeof(u_node));

    load_user(list_u);

    //大结构体链表起始
    f_list list_f = malloc(sizeof(f_node));

    load_ticket(list_f);

    int so_fd = init_sock(argv[1]);

    //大结构体链表起始
    cp_list c_list = malloc(sizeof(c_node));

    c_list->flist = list_f;
    c_list->ulist = list_u;

    add_thread(so_fd, c_list);

    // 6）挂断
    close(so_fd);

    return 0;
}

int add_thread(int so_fd, cp_list c_list)
{
    struct sockaddr_in cliaddr;
    socklen_t len = sizeof(cliaddr);
    bzero(&cliaddr, len);

    // 初始化头结点
    INIT_LIST_HEAD(&c_list->head);
    pthread_mutex_t m;
    pthread_mutex_init(&m, NULL);

    c_list->m = m;

    while (1)
    {
        int concetfd = accept(so_fd, (struct sockaddr *)&cliaddr, &len);

        if (concetfd > 0)
        {
            printf("concet : %d \n", concetfd);
            printf("new connection : %s \n", inet_ntoa(cliaddr.sin_addr));

            c_node *cl_n = malloc(sizeof(c_node));

            bzero(cl_n, sizeof(c_node));
            cl_n->confd = concetfd;
            strcpy(cl_n->ip, inet_ntoa(cliaddr.sin_addr));
            cl_n->m = m;
            cl_n->flist = c_list->flist;
            cl_n->ulist = c_list->ulist;

            pthread_mutex_lock(&m); // 多线程时,公共资源都需要上锁
            list_add(&cl_n->head, &c_list->head);
            pthread_mutex_unlock(&m);

            pthread_attr_t attr;
            pthread_attr_init(&attr);                                    // 设置属性
            pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED); // 设置分离属性
            pthread_attr_setschedpolicy(&attr, SCHED_RR);                // 调度属性设为轮播

            // 4）等待服务器连接
            pthread_t s_pid;

            if ((pthread_create(&s_pid, &attr, read_msg, (void *)cl_n)) != 0)
            {
                printf("get pthread create failed!\n");
            }
        }
    }
}

int init_sock(const char *str_port)
{
    //     1）创建未连接套接字
    int so_fd = socket(AF_INET, SOCK_STREAM, 0);

    if (so_fd == -1)
    {
        fprintf(stderr, "[%d] Failed to create unconnected socket \n", __LINE__);
    }

    // 2）服务器设置IP地址时，可以使用一个宏：
    struct sockaddr_in addr;
    socklen_t len = sizeof(addr);
    bzero(&addr, len);

    addr.sin_family = AF_INET;                //协议
    addr.sin_port = htons(atoi(str_port));    //端口号
    addr.sin_addr.s_addr = htonl(INADDR_ANY); // ip地址

    // 绑定
    if (bind(so_fd, (struct sockaddr *)&addr, len) == -1)
    {
        fprintf(stderr, "[%d]: Failed to bind socket to network address \n", __LINE__);
    }

    // 3）设置监听套接字 设置可以同时访问的人为5个
    if (listen(so_fd, 5) == -1)
    {
        fprintf(stderr, "[%d]: lsiten failed \n", __LINE__);
    }

    return so_fd;
}

void handler(void *arg) // 线程取消处理例程
{
    cp_list pos = (cp_list)arg;
    pthread_mutex_t m = pos->m;

    close(pos->confd);
    // 加锁
    pthread_mutex_lock(&m);
    list_del(&pos->head);
    // 解锁
    pthread_mutex_unlock(&m);
    free(pos);
}

void *read_msg(void *arg) // 线程例程函数
{

    cp_list pos = (cp_list)arg;

    pthread_mutex_t m = pos->m;

    // 加锁前，将 handler 压入线程取消处理例程的栈中，以防中途被取消 14
    pthread_cleanup_push(handler, (void *)pos);

    printf("113, %d\n", pos->confd);
    // 5）畅聊
    char buf[200];
    while (1)
    {

        bzero(buf, sizeof(buf));

        recv(pos->confd, buf, sizeof(buf), 0);
        if (strlen(buf) <= 0)
        {
            continue;
        }

        if (strncmp(buf, "quit\n", 5) == 0)
        {
            close(pos->confd);
            // lock
            pthread_mutex_lock(&m);
            list_del(&pos->head);
            // unlock
            pthread_mutex_unlock(&m);
            free(pos);
            break;
        }

        if (strncmp(buf, "login", 5) == 0)
            login(buf, pos); //处理登录的函数
        if (strncmp(buf, "regist", 6) == 0)
            regist_s(buf, pos); // 处理注册的函数
    }

    pthread_cleanup_pop(0);
    pthread_exit(NULL);
}

int login(char *buf, cp_list c_list)
{

    char *p = strstr(buf, ":");
    printf("[%d]%s\n", __LINE__, p + 1);
    char *name = strtok(p + 1, ",");
    char *password = strtok(NULL, ",");
    printf("[%d]%s\n", __LINE__, name);
    u_list utmp, ulist;
    ulist = c_list->ulist;
    int flag = 0;
    int slen = 30;
    list_for_each_entry(utmp, &ulist->head, head)
    {
        if (strncmp(name, utmp->name, strlen(name)) == 0 && strncmp(password, utmp->password, strlen(password) - 1) == 0)
        {
            char lsmg[30] = "200:login success";
            printf("[%d]%s\n", __LINE__, utmp->password);
            if (send(c_list->confd, lsmg, slen, 0) > 0) //传入的链表不是头节点,而是使用节点,其confd有当前的连接id
            {
                flag = 1;
                printf("success msg send success\n");
            }
        }
    }
    if (flag == 0)
    {
        char lsmg[20] = "404:login failed";
        printf("[%d]%s\n", __LINE__, utmp->password);
        if (send(c_list->confd, lsmg, slen, 0) > 0) //传入的链表不是头节点,而是使用节点,其confd有当前的连接id
        {
            printf("failed msg send success\n");
        }
    }
    return 0;
}

int regist_s(char *buf, cp_list c_list)
{

    char *p = strstr(buf, ":");
    printf("[%d]%s\n", __LINE__, p + 1);
    char *name = strtok(p + 1, ",");
    char *password = strtok(NULL, ",");
    char *phone = strtok(NULL, ",");
    int code = atoi(strtok(NULL, ","));
    printf("[%d]%s\n", __LINE__, name);
    u_list ulist;
    ulist = c_list->ulist;
    int flag = 0;
    printf("%d-%d\n", __LINE__, code);

    if (code == 111111)
    {
        u_node *unode = malloc(sizeof(u_node));
        unode->m = ulist->m;
        strncpy(unode->name, name, 20);
        strncpy(unode->password, password, 20);
        strncpy(unode->phone, phone, 11);
        unode->status = 0; // Initial login status 0 just registered
        // lock
        pthread_mutex_lock(&ulist->m);
        list_add(&unode->head, &ulist->head);
        // unlock
        pthread_mutex_unlock(&ulist->m);

        sprintf(buf, "%s,%s,%s,%d\n", name, password, phone, 0);

        pthread_mutex_lock(&ulist->m);
        int usfd;
        open_file(&usfd, "data/user_db.txt");
        write(usfd, buf, strlen(buf));
        close(usfd);
        // unlock
        pthread_mutex_unlock(&ulist->m);

        char lsmg[20] = "200:regist success";
        printf("[%d]%s\n", __LINE__, unode->password);
        if (send(c_list->confd, lsmg, 30, 0) > 0) //传入的链表不是头节点,而是使用节点,其confd有当前的连接id
        {
            flag = 1;
            printf("success msg send success\n");
        }
    }

    if (flag == 0)
    {
        char lsmg[20] = "404:regist failed";
        printf("[%d]%s\n", __LINE__, password);
        if (send(c_list->confd, lsmg, 30, 0) > 0) //传入的链表不是头节点,而是使用节点,其confd有当前的连接id
        {
            printf("failed msg send success\n");
        }
    }
    return 0;
}