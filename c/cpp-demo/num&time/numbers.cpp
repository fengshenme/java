/*

C++ 数字
通常，当我们需要用到数字时，我们会使用原始的数据类型，如 int、short、long、float 和 double 等等。
这些用于数字的数据类型，其可能的值和数值范围，我们已经在 C++ 数据类型一章中讨论过。
C++ 定义数字
我们已经在之前章节的各种实例中定义过数字。下面是一个 C++ 中定义各种类型数字的综合实例：

*/
#include <iostream>
#include <cmath>
#include <ctime>
#include <cstdlib>
using namespace std;

void funcnum();
void randoma();
 
int main ()
{
   // 数字定义
   short  s;
   int    i;
   long   l;
   float  f;
   double d;
   
   // 数字赋值
   s = 10;      
   i = 1000;    
   l = 1000000; 
   f = 230.47;  
   d = 30949.374;
   
   // 数字输出
   cout << "short  s :" << s << endl;
   cout << "int    i :" << i << endl;
   cout << "long   l :" << l << endl;
   cout << "float  f :" << f << endl;
   cout << "double d :" << d << endl;
    funcnum();
   randoma();
   return 0;
}

/*

C++ 随机数
在许多情况下，需要生成随机数。关于随机数生成器，有两个相关的函数。
一个是 rand()，该函数只返回一个伪随机数。生成随机数之前必须先调用 srand() 函数。
下面是一个关于生成随机数的简单实例。实例中使用了 time() 函数来获取系统时间的秒数，通过调用 rand() 函数来生成随机数：

*/
void randoma(){
    int i,j;
 
   // 设置种子
   srand( (unsigned)time( NULL ) );
 
   /* 生成 10 个随机数 */
   for( i = 0; i < 10; i++ )
   {
      // 生成实际的随机数
      j= rand();
      cout <<"随机数： " << j << endl;
   }    
}

/*
C++ 数学运算
在 C++ 中，除了可以创建各种函数，还包含了各种有用的函数供您使用。这些函数写在标准 C 和 C++ 库中，叫做内置函数。您可以在程序中引用这些函数。

C++ 内置了丰富的数学函数，可对各种数字进行运算。下表列出了 C++ 中一些有用的内置的数学函数。

为了利用这些函数，您需要引用数学头文件 <cmath>。

序号	函数 & 描述
1	double cos(double);
该函数返回弧度角（double 型）的余弦。
2	double sin(double);
该函数返回弧度角（double 型）的正弦。
3	double tan(double);
该函数返回弧度角（double 型）的正切。
4	double log(double);
该函数返回参数的自然对数。
5	double pow(double, double);
假设第一个参数为 x，第二个参数为 y，则该函数返回 x 的 y 次方。
6	double hypot(double, double);
该函数返回两个参数的平方总和的平方根，也就是说，参数为一个直角三角形的两个直角边，函数会返回斜边的长度。
7	double sqrt(double);
该函数返回参数的平方根。
8	int abs(int);
该函数返回整数的绝对值。
9	double fabs(double);
该函数返回任意一个浮点数的绝对值。
10	double floor(double);
该函数返回一个小于或等于传入参数的最大整数。
下面是一个关于数学运算的简单实例：
*/
void funcnum(){
    // 数字定义
   short  s = 10;
   int    i = -1000;
   long   l = 100000;
   float  f = 230.47;
   double d = 200.374;
 
   // 数学运算
   cout << "sin(d) :" << sin(s) << endl;
   cout << "abs(i)  :" << abs(i) << endl;
   cout << "floor(d) :" << floor(l) << endl;
   cout << "sqrt(f) :" << sqrt(f) << endl;
   cout << "pow( d, 2) :" << pow(d, 2) << endl;

}
