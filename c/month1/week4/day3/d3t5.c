#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/mman.h>
#include <linux/input.h>

//映射显存

int open_file(char *path);
//获取点击的x,y坐标轴
void getxy(int lcd_fd, int *x_tmp, int *y_tmp);

int main(int argc, char const *argv[])
{
    // 1.打开触摸屏文件
    int ts_fd;  // 触摸屏设备文件描述符
    ts_fd = open_file("/dev/input/event0");

        /*
    输入子系统信息结构体：
struct input_event {  //在64位系统占24个字节 
	struct timeval time;		//事件发生的时间戳（一般不使用）
	__u16 type;		//事件的类型：鼠标、键盘、触摸屏
	__u16 code;		//事件的编码：触摸屏的具体操作（X轴、Y轴）
	__s32 value;		//事件的数值：触摸屏坐标数据
    事件编码：
类型：
#define EV_SYN			0x00		
#define EV_KEY			0x01		键盘、触摸屏点击。
#define EV_REL			0x02		相对位移：鼠标
#define EV_ABS			0x03		绝对位移：触摸屏
编码：
#define BTN_TOUCH		0x14a	触摸屏点击
#define ABS_X			0x00			X轴
#define ABS_Y			0x01			Y轴
获得如下数据：
type:0x3 code:0x0 value:379		触摸屏x坐标：379
type:0x3 code:0x1 value:293		触摸屏y坐标：293
type:0x1 code:0x14a value:1		触摸屏按下
type:0x0 code:0x0 value:0		//分隔符
type:0x1 code:0x14a value:0		触摸屏松开
type:0x0 code:0x0 value:0		//分隔符
    */
        // 2.读取触摸屏数据
        
    int x_tmp = 0, y_tmp = 0;
    while (1)
    {
        getxy(ts_fd,  &x_tmp, &y_tmp);
        printf("(%d, %d)\n", x_tmp, y_tmp);
    }

    // 3.关闭触摸屏文件
    close(ts_fd);

    return 0;
}

//获取点击x,y坐标轴
void getxy(int ts_fd,  int *x, int *y)
{
    struct input_event touch_data;
    bzero(&touch_data, sizeof(touch_data));
    read(ts_fd, &touch_data, sizeof(touch_data));
    if (touch_data.type == 3)
    {
        if (touch_data.code == 0)
            *x = touch_data.value;
        if (touch_data.code == 1)
            *y = touch_data.value;
        if (*x != 0 && *y != 0)
        {
            *x = (*x) * 800 / 1024;
            *y = (*y) * 480 / 600;
        }
    }
    if (touch_data.type == EV_KEY && touch_data.code == BTN_TOUCH && touch_data.value == EV_SYN)
    {
        *x = 0;
        *y = 0;
    }
}

//打开linux 的linux文件
int open_file(char *path)
{
    int lcd_fd;                    //定义变量
    lcd_fd = open(path, O_RDONLY); //打开文件
    if (lcd_fd == -1)              //判断lcd_fd是否等于-1,等于（打开失败）
    {
        perror("open lcd failed"); //打开失败输出open failed
        return 1;
    }
    return lcd_fd;
}