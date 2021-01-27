#include "../include/head.h"

int add_flights(u_node *unode, int sofd);
int adminlogin(int sofd);
int admin(u_node *unode, int sofd);

int index_t(const char *ip, const char *port)
{
    int sofd;
    int num;
    while (1)
    {

        va("=");
        printf("\t\t火星机场购票系统\n");
        printf("1)登录\t2)注册\t3)忘记密码\t4)管理员登录\n");
        va("=");
        printf("请选择对应服务 ,输入对应数字序号进入:");

        scanf("%d", &num);
        while (getchar() != '\n')
            ;
        switch (num)
        {
        case 1:
            printf("您选择了登录\n");
            sofd = init_sock(ip, port);
            login(sofd);
            close(sofd);
            break;
        case 2:
            printf("您选择了注册\n");
            sofd = init_sock(ip, port);
            user_regist(sofd);
            close(sofd);
            break;
        case 3:
            printf("您选择了忘记密码\n");

            sofd = init_sock(ip, port);
            repassword(sofd);
            close(sofd);
            break;
        case 4:
            printf("您选择了管理员登录\n");

            sofd = init_sock(ip, port);
            adminlogin(sofd);
            close(sofd);
            break;

        default:
            break;
        }
    }
    return 0;
}

int va(char *ch)
{
    int i;
    for (i = 0; i < 75; i++)
    {
        printf("%s", ch);
    }
    printf("\n");
    return 0;
}

int init_sock(const char *ip, const char *port)
{

    //ipv4 tcp连接
    int sofd = socket(AF_INET, SOCK_STREAM, 0);

    // 将文本ip转换为二进制网络字节数
    struct sockaddr_in addr;
    socklen_t len = sizeof(struct sockaddr_in);

    addr.sin_family = AF_INET;
    addr.sin_port = htons(atoi(port));
    // AF_INET 使用ipv4
    inet_pton(AF_INET, ip, &addr.sin_addr);

    if (connect(sofd, (struct sockaddr *)&addr, len) == -1)
    {
        fprintf(stdin, "[%d] line : connect failed \n", __LINE__);
    }
    return sofd;
}

int login(int sofd)
{

    u_node *unode = malloc(sizeof(u_node));
    bzero(unode, UNSIZE);

    printf("用户名:");
    fgets(unode->name, 20, stdin);
    printf("密码:");
    fgets(unode->password, 20, stdin);

    memrep(unode, '\n', UNSIZE);

    unode->cmd = LOGIN;
    if (send(sofd, unode, UNSIZE, 0) < 0)
    {
        printf("%d=>send failed\n", __LINE__);
    }

   
    while (1)
    {
         bzero(unode, UNSIZE);
        recv(sofd, unode, UNSIZE, 0);

        if (unode->cmd < 200)
        {
            continue;
        }

        if (unode->cmd == 200)
        {
            printf(">登录成功, 欢迎%s用户<", unode->name);
            // printf("%d=>%s,%s,%s,%s,%hd,%d,%u\n", __LINE__, unode->id, unode->name, unode->password, unode->phone, unode->status, unode->account, unode->vipclass);
            use_admin(unode, sofd);
            break;
        }
        else if (unode->cmd == 404)
        {
            printf("密码或账号错误,\n");
            break;
        }

    }
    // 释放内存,关闭文件

    return 0;
}

int adminlogin(int sofd)
{

    u_node *unode = malloc(sizeof(u_node));
    bzero(unode, sizeof(u_node));

    printf("用户名:");
    fgets(unode->name, 20, stdin);
    printf("密码:");
    fgets(unode->password, 20, stdin);

    // sprintf(buf, "adminlogin:%s,%s", name, password);
    // strrep(buf, '\n');
    memrep(unode, '\n', UNSIZE);
    unode->cmd = ADMINLOGIN;
    if (send(sofd, unode, UNSIZE, 0) < 0)
    {
        printf("%d=>send failed\n", __LINE__);
    }
    while (1)
    {
        bzero(unode, UNSIZE);
        recv(sofd, unode, UNSIZE, 0);

        if (unode == NULL)
        {
            continue;
        }

        if (unode->cmd == 200)
        {
            printf("\t >登录成功<\n");

            admin(unode, sofd);
            break;
        }

        if (unode->cmd == 404)
        {
            printf("密码或账号错误,是否重置密码[y/n]");

            break;
        }
    }

    if (fgetc(stdin) == 'y')
    {
    }
    printf("\n");
    // 释放内存,关闭文件

    return 0;
}

int user_regist(int sofd)
{
    va("=");
    printf("\t欢迎注册成为鲲鹏航空公司的用户\t\n");
    u_node *unode = malloc(UNSIZE);
    char npassword[20];
    while (1)
    {
        bzero(unode, UNSIZE);

        bzero(npassword, 20);

        printf("用户名:");
        fgets(unode->name, 20, stdin);
        printf("密码:");
        fgets(unode->password, 20, stdin);
        printf("请再次输入密码:");
        fgets(npassword, 20, stdin);

        if (strncmp(unode->password, npassword, 20) != 0)
        {
            printf("两次密码不一致请重新输入\n");
            continue;
        }
        printf("手机号:");
        fgets(unode->phone, 20, stdin);
        if (strlen(unode->phone) != 12)
        {
            printf("电话号码格式不对,重新填写\n");
            continue;
        }
        printf("手机短信验证码:(目前1212)");
        char code[6];
        fgets(code, 5, stdin);
        unode->code = atoi(code);
        unode->cmd = REGIST;
        memrep(unode, '\n', UNSIZE);
        // printf("%d -%s\n", __LINE__, buf);
        if (send(sofd, unode, UNSIZE, 0) > 0)
        {
            printf("regist msg send success\n");
        }

        bzero(unode, UNSIZE);
        recv(sofd, unode, UNSIZE, 0);

        if (unode == NULL)
        {
            continue;
        }
        if (unode->cmd == 200)
        {
            printf("[%d] 注册成功,请登录\n", __LINE__);
            // index_t(sofd);
            break;
        }

        if (unode->cmd == 404)
        {
            bzero(unode, UNSIZE);
            printf("注册失败,是否重新注册[y/n]");
            if (fgetc(stdin) == 'y')
            {
                continue;
            }
            else
            {
                break;
            }
        }
    }
    // 释放内存,关闭文件
    free(unode);

    return 0;
}

void debugf()
{
    fprintf(stderr, "%d]~~~~~~~~~~~~~~~~~~~~~~~~~", __LINE__);
}

int use_admin(u_node *unode, int sofd) // 这里传入的name是用户详情信息
{
    int seconds = time((time_t *)NULL);
    int rets;

    // if (recv(sofd, bufa, sizeof(u_node), 0) > 0)
    // {
    //     printf("%d] %s", __LINE__, bufa);
    // }
    while (1)
    {
        rets = time((time_t *)NULL);
        if (rets - seconds > 360) // 无操作5分钟退出连接
        {
            logout(unode, sofd);
            break;
        }
        short num;

        printf("\n");
        va("=");
        printf("您好: %s用户\t\t用户中心\n", unode->name);
        printf(" 1.航班列表\t 2. 查询航班 \t 3. 快速查询\t \n");
        printf(" 4.订购航班\t 5. 已购航班 \t 6. 航班退票\t \n");
        printf(" 7.查询余额\t 8. 充值账户 \t 9. 修改信息\t \n");
        printf(" 10.取票服务\t 11.打印发票 \t 12.退出登录 \t \n");
        va("*");
        printf("请选择对应服务 ,输入对应数字序号进入:");
        scanf("%hd", &num);
        while (getchar() != '\n')
            ;
        seconds = rets;
        switch (num)
        {
        case 1:
            printf("您选择了航班列表\n");
            getflight_list(unode, sofd);

            break;
        case 2:
            printf("您选择了查询航班\n");
            search_flight(unode, sofd);
            break;
        case 3:
            printf("您选择了快速查询\n");
            quick_searchf(unode, sofd);
            break;
        case 4:
            printf("您选择了订购航班\n");
            booking_flights(unode, sofd);
            break;
        case 5:
            printf("您选择了已购航班\n");
            find_buyed_flight(unode, sofd);
            break;
        case 6:
            printf("您选择了航班退票\n");
            refunded(unode, sofd);
            break;
        case 7:
            balance_inquiry(unode, sofd);
            break;
        case 8:
            recharge(unode, sofd); // 账户充值
            break;
        case 9:
            printf("您选择了修改信息\n");
            change_userinfo(unode, sofd);
            break;
        case 10:
            printf("您选择了取票服务\n");
            draw_bill(unode, sofd);
            break;
        case 11:
            printf("您选择了打印发票\n");
            print_invoice(unode, sofd);
            break;
        case 12:
            printf("您选择了退出登录\n");
            if (logout(unode, sofd) == 0)
                return 0;
            break;

        default:
            continue;
        }
    }
    return 0;
}

int admin(u_node *unode, int sofd)
{
    char *name = unode->name;
    int seconds = time((time_t *)NULL);
    int rets;
    char bufa[20];
    if (recv(sofd, bufa, sizeof(u_node), 0) > 0)
    {
        printf("%d] %s", __LINE__, bufa);
    }
    while (1)
    {
        rets = time((time_t *)NULL);
        if (rets - seconds > 360) // 无操作5分钟退出连接
        {
            logout(unode, sofd);
            break;
        }
        short num;

        printf("\n");
        va("=");
        printf("您好: %s用户\t\t用户中心\n", name);
        printf(" 1.航班列表\t 2. 查询航班 \t 3. 快速查询\t \n");
        printf(" 4.录入航班\t 5. 删除航班 \t 6. 已删航班\t \n");
        printf(" 7.退出登录 \t \n");
        va("*");
        printf("请选择对应服务 ,输入对应数字序号进入:");
        scanf("%hd", &num);
        while (getchar() != '\n')
            ;
        seconds = rets;
        switch (num)
        {
        case 1:
            printf("您选择了航班列表\n");
            getflight_list(unode, sofd);

            break;
        case 2:
            printf("您选择了查询航班\n");
            search_flight(unode, sofd);
            break;
        case 3:
            printf("您选择了快速查询\n");
            quick_searchf(unode, sofd);
            break;
        case 4:
            printf("您选择了录入航班\n");
            add_flights(unode, sofd);
            break;
        case 5:
            printf("您选择了删除航班\n");
            find_buyed_flight(unode, sofd);
            break;
        case 6:
            printf("您选择了已删航班\n");
            refunded(unode, sofd);
            break;
        case 7:
            printf("您选择了退出登录\n");
            if (logout(unode, sofd) == 0)
                return 0;
            break;

        default:
            continue;
        }
    }
    return 0;
}

int strrep(char *str, char del) // 删除指定字符
{
    int i, j, k = strlen(str);
    for (i = 0; i < k; i++)
    {
        if (str[i] == del)
        {
            for (j = i; j < k; j++)
            {
                str[j] = str[j + 1];
            }
            i--;
            k--;
        }
    }
    return 0;
}

int memrep(void *str, char del, int num) // 删除指定字符
{
    char *p;
    while ((p = memchr(str, del, num)) != 0)
    {
        *p = '\0';
    }
    return 0;
}

int repassword(int sofd)
{
    va("=");
    printf("\t\t密码找回\t\n");
    u_node *unode = malloc(UNSIZE);
    char code[7];
    while (1)
    {
        bzero(unode, UNSIZE);
        printf("用户名:"); // 15800998866
        fgets(unode->name, 20, stdin);

        printf("手机号:");
        fgets(unode->phone, 20, stdin);
        if (strlen(unode->phone) != 12)
        {
            printf("电话号码格式不对,重新填写\n");
            continue;
        }
        printf("手机短信验证码:(目前1212)");
        fgets(code, 7, stdin);
        unode->code = atoi(code);
        printf("新密码:");
        fgets(unode->password, 20, stdin);

        // printf("%d -%s\n", __LINE__, buf);
        unode->cmd = REPASS;
        if (send(sofd, unode, UNSIZE, 0) < 0)
        {
            printf("[%d] repass msg send failed\n", __LINE__);
        }

        bzero(unode, UNSIZE);
        recv(sofd, unode, UNSIZE, 0);

        if (unode->cmd == 0)
        {
            continue;
        }
        if (unode->cmd == 200)
        {
            printf("[%d] 密码重置成功,请登录\n", __LINE__);
            // index_t(sofd);
            break;
        }

        if (unode->cmd == 404)
        {
            printf("密码重置失败,是否重新设置[y/n]");
            if (fgetc(stdin) == 'y')
            {
                continue;
            }
            else
            {
                break;
            }
        }
    }
    free(unode);
    return 0;
}

int getflight_list(u_node *unode, int sofd)
{
    int buf_s = 1024;
    char *bufl = malloc(buf_s);
    char(*flight)[256] = calloc(256, 200);
    int i = 0;

    bzero(bufl, buf_s);
    bzero(flight, 256 * 200);

    unode->cmd = FLIGHTLIST;
    if (send(sofd, unode, UNSIZE, 0) <= 0)
    {
        printf("[%d] send failed\n", __LINE__);
    }

    while (1)
    {

        bzero(bufl, buf_s);
        recv(sofd, bufl, buf_s, 0);

        if (strlen(bufl) <= 3)
        {
            continue;
        }
        // printf("%d %s\n", __LINE__, bufl);
        // printf("%d %s\n", __LINE__, unode->id);
        get_f(bufl, flight, &i);
        break;
    }

    show_flight(flight, i);
    free(flight);
    // 释放内存,关闭文件
    free(bufl);

    printf("返回请按[y]");
    if (fgetc(stdin) == 'y')
    {
        printf("\n");
    }

    return 0;
}

// 多条件搜索航班
int search_flight(u_node *unode, int sofd)
{
    char des[20];
    char botime[20];
    char ftype[2];
    char price[8];
    char(*flight)[256] = calloc(256, 200);

    int i = 0;

    bzero(flight, 256 * 200);

    int buf_s = 1024;
    char *buf = malloc(buf_s);

    bzero(des, 20);
    bzero(botime, 20);
    bzero(price, 8);
    printf("目的地:");
    fgets(des, 20, stdin);
    printf("出发日期:");
    fgets(botime, 20, stdin);
    printf("机型:");
    fgets(ftype, 2, stdin);
    printf("价格以下:");
    scanf("%s", price);
    while (getchar() != '\n')
        ;

    bzero(buf, buf_s);
    sprintf(buf, "%s,%s,%s,%s", des, botime, ftype, price);
    strrep(buf, '\n');
    unode->cmd = SELECTF;
    strncpy(unode->msg, buf, strlen(buf));
    if (send(sofd, unode, UNSIZE, 0) <= 0)
    {
        printf("get send failed\n");
    }

    while (1)
    {

        bzero(buf, buf_s);
        recv(sofd, buf, buf_s, 0);

        if (strlen(buf) <= 3)
        {
            continue;
        }
        // printf("%d %s\n", __LINE__, buf);
        get_f(buf, flight, &i);
        break;
    }

    if (i > 0)
    {
        show_flight(flight, i);
    }
    else
    {
        printf("没有符合条件的航班....");
    }

    free(flight);
    // 释放内存,关闭文件
    free(buf);
    printf("返回请按[y]");
    if (fgetc(stdin) == 'y')
    {
        printf("\n");
    }

    return 0;
}

int add_flights(u_node *unode, int sofd)
{
    char flinum[20];
    char start[20];
    char des[20];
    char address[20];
    char ftype;
    char botime[10];
    unsigned int price;
    unsigned int surplusVote;

    va("*");

    int buf_s = 1024;
    char *buf = malloc(buf_s);

    bzero(flinum, 20);
    bzero(start, 20);
    bzero(des, 20);
    bzero(botime, 10);

    printf("航班号:");
    fgets(flinum, 20, stdin);
    printf("出发地:");
    fgets(start, 20, stdin);
    printf("目的地:");
    fgets(des, 20, stdin);
    printf("班期:");
    fgets(address, 20, stdin);
    printf("机型:");
    scanf("%c", &ftype);
    while (getchar() != '\n')
        ;
    printf("登机时间:");
    fgets(botime, 20, stdin);
    printf("价格:");
    scanf("%u", &price);
    while (getchar() != '\n')
        ;
    printf("初始票数:");
    scanf("%u", &surplusVote);
    while (getchar() != '\n')
        ;
    bzero(buf, buf_s);
    sprintf(buf, "addflight:%s,%s,%s,%s,%c,%s,%u,%u", flinum, start, des, address, ftype, botime, price, surplusVote);
    strrep(buf, '\n');

    if (send(sofd, buf, strlen(buf), 0) <= 0)
    {
        printf("get send failed\n");
    }

    while (1)
    {

        bzero(buf, buf_s);
        recv(sofd, buf, buf_s, 0);

        if (strlen(buf) <= 3)
        {
            continue;
        }
        // char *p = strstr(buf, ":");
        if (atoi(buf) == 200)
        {
            printf("[%d] 航班添加成功\n", __LINE__);
        }

        if (atoi(buf) == 404)
        {
            printf("航班添加失败\n");
        }
        break;
    }

    // 释放内存,关闭文件
    free(buf);
    printf("返回请按[y]");
    if (fgetc(stdin) == 'y')
    {
        printf("\n");
    }

    return 0;
}

int quick_searchf(u_node *unode, int sofd)
{
    va("=");
    printf("\t\t快速查询\t\n");
    char fln[10];
    char(*flight)[256] = calloc(256, 200);
    int i = 0;

    bzero(flight, 256 * 200);

    int buf_s = 1024;
    char *buf = malloc(buf_s);

    bzero(fln, 10);
    printf("输入航班号:");
    fgets(fln, 10, stdin);

    strrep(fln, '\n');

    strncpy(unode->msg, fln, strlen(fln));
    unode->cmd = SELECTQ;
    if (send(sofd, unode, UNSIZE, 0) <= 0)
    {
        printf("%d => get send failed\n", __LINE__);
    }
    while (1)
    {

        bzero(buf, buf_s);
        recv(sofd, buf, buf_s, 0);

        if (strlen(buf) <= 3)
        {
            continue;
        }
        printf("%d-%s\n", __LINE__, buf);
        get_f(buf, flight, &i);

        break;
    }

    if (i > 0)
    {
        show_flight(flight, i);
    }
    else
    {
        printf("没有符合条件的航班....\n");
    }

    free(flight);
    // 释放内存,关闭文件
    free(buf);

    printf("返回请按[y]");
    if (fgetc(stdin) == 'y')
    {
        printf("\n");
    }

    return 0;
}

// 获取航班信息的公共部分
int get_f(char *buf, char (*flight)[256], int *i)
{

    if (atoi(buf) == 200) //成功的头部信息是200
    {
        char *p = strstr(buf, ":");
        // char *np = strstr(p + 1, ":");
        // printf("%d=>%s\n", __LINE__, buf);

        char *pp = strtok(p + 1, "\n"); // 获取到第一条航班信息
        while (pp != NULL)
        {

            if (pp != NULL)
            {

                strncpy(flight[*i], pp, 256);
                (*i)++;
            }
            pp = strtok(NULL, "\n");
        }

        return 0;
    }

    if (atoi(buf) == 404)
    {
        printf("航班信息获取失败....\n");
        return -1;
    }
    return 0;
}

int show_flight(char (*flight)[256], int i)
{
    va("=");
    printf("\t\t航班列表\t\n");
    va("=");
    printf("\n");
    va("*");
    printf("航班号\t起点站\t\t出发站\t班期\t\t机型\t起飞时间 票价\t余票\n");
    int j;
    for (j = 0; j < i; j++)
    {
        //  flight[i] 指针变量相当于flight + 1指针变量访问的第一个维度元素
        //   printf("%d-%s\n",__LINE__,flight[j] );
        char *pp = strtok(flight[j], ",");
        if (pp != NULL)
        {
            printf("%s\t", pp);
        }
        pp = strtok(NULL, ",");
        if (pp != NULL)
        {
            printf("%s\t", pp);
        }
        printf("--->\t");

        while (pp != NULL)
        {
            pp = strtok(NULL, ",");
            if (pp != NULL)
            {
                printf("%s\t", pp);
            }
        }
        printf("\n");
    }
    return 0;
}

int ashow_flight(char (*flight)[256], int i)
{
    va("=");
    printf("\t\t航班列表\t\n");
    va("=");
    printf("\n");
    va("*");
    printf("航班号\t起点站\t出发站\t班期\t\t机型\t起飞时间  票价\t出票状态\n");
    int j, k;
    for (j = 0; j < i; j++)
    {
        //  flight[i] 指针变量相当于flight + 1指针变量访问的第一个维度元素
        //   printf("%d-%s\n",__LINE__,flight[j] );
        k = 0;
        char *pp = strtok(flight[j], ",");
        if (pp != NULL)
        {
            printf("%s\t", pp);
        }
        pp = strtok(NULL, ",");
        if (pp != NULL)
        {
            printf("%s", pp);
        }
        // printf("-->");

        while (pp != NULL)
        {
            pp = strtok(NULL, ",");
            if (pp != NULL)
            {
                if (k == 5)
                {
                    if (atoi(pp) == 0)
                        printf("\t未出票");
                    if (atoi(pp) >= 1)
                        printf("\t已出票");
                }
                else
                {
                    printf("\t%s", pp);
                }

                k++;
            }
        }
        printf("\n");
    }
    return 0;
}

int recharge(u_node *unode, int sofd)
{
    va("=");
    printf("%s 用户 \t\t充值中心\t\n", unode->name);
    int buf_s = 1024;
    char *buf = malloc(buf_s);
    char *money = malloc(9);

    bzero(money, 9);
    int flag = 0;

    printf("充值金额:"); // 15800998866
    fgets(money, 9, stdin);

    if (atoi(money) <= 0)
    {
        printf("充值金额数目不对,请重新输入\n");
        recharge(unode, sofd);
        flag = -1;
    }
    strrep(money, '\n');
    strncpy(unode->msg, money, strlen(money));
    // printf("[%d] -%s\n", __LINE__, buf);
    unode->cmd = RECHARG;
    // printf("%d -%s\n", __LINE__, buf);
    if (send(sofd, unode, UNSIZE, 0) < 0)
    {
        printf("recharge msg send failed\n");
    }

    while (flag != -1)
    {

        bzero(buf, buf_s);
        recv(sofd, buf, buf_s, 0);

        if (strlen(buf) <= 0)
        {
            continue;
        }
        char *p = strstr(buf, ":");
        if (atoi(buf) == 200)
        {
            printf("[%d] 充值%d成功,欢迎购票\n", __LINE__, atoi(p + 1));
            unode->account = atoi(p + 1);
            break;
        }

        if (atoi(buf) == 404)
        {
            printf("充值失败,返回请按[y]");
            if (fgetc(stdin) == 'y')
            {
                printf("\n");
                break;
            }
        }
    }
    free(money);
    free(buf);
    return 0;
}

int balance_inquiry(u_node *unode, int sofd)
{
    va("=");
    printf("\t\t余额查询\t\n");

    char buf[128] = {0};

    unode->cmd = FINDACC;
    if (send(sofd, unode, UNSIZE, 0) < 0)
    {
        printf("recharge msg send failed\n");
    }

    while (1)
    {

        memset(buf, 0, 128);
        recv(sofd, buf, 128, 0);

        if (strlen(buf) <= 0)
            continue;

        char *p = strstr(buf, ":");
        if (atoi(buf) == 200)
        {
            unode->account = atoi(p + 1);
            printf("您好: %s用户 当前可用余额:%d\n", unode->name, unode->account);
            break;
        }

        if (atoi(buf) == 404)
        {
            printf("\t 查询失败~~~~~~\n");
            break;
        }
    }

    printf("返回按[y]");
    if (fgetc(stdin) == 'y')
    {
        printf("\n");
    }

    return 0;
}

int booking_flights(u_node *unode, int sofd)
{
    char flnum[12] = {0};
    char fltime[12] = {0};
    char buf[128] = {0};
    va("*");
    printf("请输入要购买的航班号:");
    fgets(flnum, 12, stdin);
    printf("请输入出行日期(班期):");
    fgets(fltime, 12, stdin);

    sprintf(buf, "%s,%s", flnum, fltime);
    strrep(buf, '\n');

    strncpy(unode->msg, buf, strlen(buf));
    unode->cmd = BUYFLIGHT;
    if (send(sofd, unode, UNSIZE, 0) < 0)
    {
        printf("recharge msg send failed\n");
    }
    while (1)
    {
        memset(buf, 0, 128);
        recv(sofd, buf, 128, 0);

        if (strlen(buf) <= 3)
            continue;

        char *p = strstr(buf, ":");
        if (atoi(buf) == 200)
        {
            printf("[%d] 航班购买成功=>%s\n", __LINE__, p + 1);
            break;
        }

        if (atoi(buf) == 404)
        {
            printf("航班购买失败\n");
            break;
        }
    }
    printf("返回[y]");
    if (fgetc(stdin) == 'y')
    {
        printf("\n");
    }
    return 0;
}

int find_buyed_flight(u_node *unode, int sofd)
{
    char *name = unode->name;
    va("=");
    printf("\t\t已购票查询\t\n");
    char(*flight)[256] = calloc(256, 200);
    int i = 0;

    int buf_s = 1024;
    char *buf = malloc(buf_s);
    bzero(buf, buf_s);

    sprintf(buf, "findbuyfli:%s,%s", unode->phone, name);
    strrep(buf, '\n');

    if (send(sofd, buf, strlen(buf), 0) < 0)
    {
        printf("recharge msg send failed\n");
    }

    while (1)
    {

        bzero(buf, buf_s);
        recv(sofd, buf, buf_s, 0);

        if (strlen(buf) <= 3)
        {
            continue;
        }
        // printf("%d-%s\n", __LINE__, buf);
        get_f(buf, flight, &i);

        break;
    }

    if (i > 0)
    {
        ashow_flight(flight, i);
    }
    else
    {
        printf("没有购买航班....\n");
    }

    free(flight);
    // 释放内存,关闭文件
    free(buf);
    printf("返回按[y]");
    if (fgetc(stdin) == 'y')
    {
        printf("\n");
    }

    return 0;
}

int refunded(u_node *unode, int sofd)
{
    char flnum[12] = {0};
    char fltime[12] = {0};
    char buf[128] = {0};

    va("*");
    printf("\t %s 用户, \t\t退票中心\t\n", unode->name);
    printf("请输入要退票的航班号:");
    fgets(flnum, 12, stdin);
    printf("请输入要退票的班期:");
    fgets(fltime, 12, stdin);

    sprintf(buf, "refunded:%s,%s,%s", flnum, fltime, unode->phone);
    strrep(buf, '\n');

    if (send(sofd, buf, strlen(buf), 0) < 0)
    {
        printf("recharge msg send failed\n");
    }

    while (1)
    {
        memset(buf, 0, 128);
        recv(sofd, buf, 128, 0);

        if (strlen(buf) <= 3)
            continue;

        char *p = strstr(buf, ":");
        if (atoi(buf) == 200)
        {
            printf("[%d] 航班退票成功=>%s\n", __LINE__, p + 1);
            break;
        }

        if (atoi(buf) == 404)
        {
            printf("航班退票失败\n");
            break;
        }
    }
    printf("返回[y]");
    if (fgetc(stdin) == 'y')
    {
        printf("\n");
    }
    return 0;
}

int change_ticket(u_node *unode, int sofd) // 改签
{
    return 0;
}

int change_userinfo(u_node *unode, int sofd) // 修改用户昵称
{

    va("=");
    printf("%s 用户 \t\t用户中心\t\n", unode->name);
    int buf_s = 1024;
    char *buf = malloc(buf_s);
    char *name = malloc(24);
    char *phone = malloc(13);
    bzero(buf, buf_s);

    bzero(name, 9);
    bzero(phone, 13);
    int flag = 0;

    printf("要修改的手机号:"); // 15800998866
    fgets(phone, 13, stdin);
    if (strlen(phone) <= 11)
    {
        printf("手机号不正确,请重新输入\n");
        change_userinfo(unode, sofd);
        return -1;
    }

    printf("要修改的昵称:"); // 15800998866
    fgets(name, 9, stdin);
    if (strlen(name) > 12 && strlen(name) <= 1)
    {
        printf("昵称字符不对, 请重新输入\n");
        change_userinfo(unode, sofd);
        return -1;
    }
    sprintf(buf, "reuserin:%s,%s,%s,%s", unode->phone, unode->name, phone, name);
    strrep(buf, '\n');
    printf("[%d] -%s\n", __LINE__, buf);

    // printf("%d -%s\n", __LINE__, buf);
    if (send(sofd, buf, strlen(buf), 0) < 0)
    {
        printf("change_userinfo msg send failed\n");
        change_userinfo(unode, sofd);
        return -1;
    }

    while (flag != -1)
    {

        bzero(buf, buf_s);
        recv(sofd, buf, buf_s, 0);

        if (strlen(buf) <= 0)
        {
            continue;
        }
        char *p = strstr(buf, ":");
        if (atoi(buf) == 200)
        {
            // printf("[%d] 充值成功,欢迎继续购票-%s\n", __LINE__, p + 1);
            char *pp = strtok(p + 1, ",");
            if (pp != NULL)
                strncpy(unode->phone, pp, strlen(pp));
            pp = strtok(NULL, ",");
            if (pp != NULL)
                strncpy(unode->name, pp, strlen(pp));
            printf("用户信息更新成功\n");
            break;
        }

        if (atoi(buf) == 404)
        {
            printf("修改失败,返回请按[y]");
            if (fgetc(stdin) == 'y')
            {
                printf("\n");
                break;
            }
        }
    }
    free(phone);
    free(name);
    free(buf);

    return 0;
}

int draw_bill(u_node *unode, int sofd) // 出票
{
    char flnum[12] = {0};
    char fltime[12] = {0};
    char buf[128] = {0};

    va("*");
    printf("\t %s 用户, \t\t出票中心\t\n", unode->name);
    printf("请输入要出票的航班号:");
    fgets(flnum, 12, stdin);
    printf("请输入要出票的班期:");
    fgets(fltime, 12, stdin);

    sprintf(buf, "drawbill:%s,%s", flnum, fltime);
    strrep(buf, '\n');
    printf("[%d] -%s\n", __LINE__, buf);

    // printf("%d -%s\n", __LINE__, buf);
    if (send(sofd, buf, strlen(buf), 0) < 0)
    {
        printf("change_userinfo msg send failed\n");
        change_userinfo(unode, sofd);
        return -1;
    }
    char tmp[256] = {0};
    while (1)
    {
        memset(buf, 0, 128);
        recv(sofd, buf, 128, 0);

        if (strlen(buf) <= 3)
            continue;

        char *p = strstr(buf, ":");
        if (atoi(buf) == 200)
        {
            strncpy(tmp, p + 1, 256);
            printf("[%d] 航班出票成功=>%s\n", __LINE__, p + 1);
            break;
        }

        if (atoi(buf) == 404)
        {
            printf("航班出票失败\n");
            break;
        }
    }
    char *pn = strtok(tmp, ",");
    va("*");
    va("*");
    printf("\t\t\t鲲鹏航空|<->|登机牌\t\t\t\n");
    printf("\t姓名: %s\t\t\t航班号:%s\t\n", unode->name, pn);
    pn = strtok(NULL, ",");
    printf("\t起始地: %s", pn);
    pn = strtok(NULL, ",");
    printf("\t\t\t目的地: %s\t\n", pn);
    pn = strtok(NULL, ",");
    printf("\t登机日期: %s\t", pn);
    pn = strtok(NULL, ",");
    printf("\t登机时间: %s\t\n", pn);
    // pn = strtok(NULL, ",");
    // printf("\t\t出票转台: %s\t\n", pn);
    va("*");
    va("*");
    printf("返回[y]");
    if (fgetc(stdin) == 'y')
    {
        printf("\n");
    }

    return 0;
}

// 打印发票
int print_invoice(u_node *unode, int sofd)
{
    char flnum[12] = {0};
    char fltime[12] = {0};
    char buf[128] = {0};

    va("*");
    printf("\t %s 用户, \t\t发票中心\t\n", unode->name);
    printf("请输入要打印发票的航班号:");
    fgets(flnum, 12, stdin);
    printf("请输入要打印发票的班期:");
    fgets(fltime, 12, stdin);

    sprintf(buf, "pinvoice:%s,%s,%s", flnum, fltime, unode->phone);
    strrep(buf, '\n');

    // printf("%d -%s\n", __LINE__, buf);
    if (send(sofd, buf, strlen(buf), 0) < 0)
    {
        printf("change_userinfo msg send failed\n");
        change_userinfo(unode, sofd);
        return -1;
    }
    char tmp[256] = {0};
    while (1)
    {
        memset(buf, 0, 128);
        recv(sofd, buf, 128, 0);

        if (strlen(buf) <= 3)
            continue;

        char *p = strstr(buf, ":");
        printf("[%d] -%s\n", __LINE__, buf);
        if (atoi(buf) == 200)
        {
            strncpy(tmp, p + 1, 256);
            printf("[%d] 航班发票打印成功=>%s\n", __LINE__, p + 1);
            break;
        }

        if (atoi(buf) == 404)
        {
            printf("航班发票打印失败\n");
            break;
        }
    }
    char *pn = strtok(tmp, ",");
    va("*");
    printf("\t\t\t广东增值税电子普通发票\t\t\t\n");
    printf("* 购\t购买方名称: 个人\t\t\t\n");
    printf("* 买\t纳税人识别号: \t\t\t\n");
    printf("* 方\t地址: \t\t\t\n");
    printf("* -\t开户行及账号: \t\t\t\n");
    va("-");
    printf("* 服务名称\t规格型号\t单位\t数量\t单价\t金额\t税率\t税额\t\n");
    printf("* 飞机票\t%s\t\t 张\t 1", strlen(pn) >= 0 ? pn : "???"); // 航班号
    pn = strtok(NULL, ",");
    printf("\t%s", strlen(pn) >= 0 ? pn : "???");                  // 单价
    printf("\t%s", pn);                                            // 金额
    printf("\t13%c", '%');                                         // 税率
    printf("\t%.1f\t\n", strlen(pn) >= 0 ? atof(pn) * 0.13 : 0.0); // 税额
    va("-");
    printf("\t合计\t\t\t\t\t%s\t\n", pn);
    // pn = strtok(NULL, ",");
    // printf("\t\t出票转台: %s\t\n", pn);
    va("-");
    printf("* 销\t销售方名称: 鲲鹏航空航天集团\t\t\t\n");
    printf("* 售\t纳税人识别号: 914401058500666\t\t\t\n");
    printf("* 方\t地址: 广州天河区天普西路1号\t\t\t\n");
    printf("* -\t开户行及账号: 中国银行 890020133920\t\t\t\n");
    va("*");
    printf("返回[y]");
    if (fgetc(stdin) == 'y')
    {
        printf("\n");
    }

    return 0;
}

int logout(u_node *unode, int sofd)
{
    int buf_s = 1024;
    char *buf = malloc(buf_s);
    bzero(buf, buf_s);

    sprintf(buf, "logout:%s,%s", unode->name, unode->phone);
    strrep(buf, '\n');

    if (send(sofd, buf, strlen(buf), 0) < 0)
    {
        printf("%d=>send failed\n", __LINE__);
    }
    int flag = 0;
    while (1)
    {
        bzero(buf, buf_s);
        recv(sofd, buf, buf_s, 0);

        if (strlen(buf) <= 0)
        {
            continue;
        }

        if (atoi(buf) == 200)
        {
            printf("\t >退出登录成功<\n");

            break;
        }

        if (atoi(buf) == 404)
        {
            printf("退出失败请重试\n");
            flag = -1;
            break;
        }
    }
    free(buf);
    if (flag == -1)
    {
        return -1;
    }
    // 释放内存,关闭文件

    free(unode);

    return 0;
}