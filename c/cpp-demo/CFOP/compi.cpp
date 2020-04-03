/*
# 和 ## 运算符
# 和 ## 预处理运算符在 C++ 和 ANSI/ISO C 中都是可用的。# 运算符会把 replacement-text 令牌转换为用引号引起来的字符串。
请看下面的宏定义：
*/
#include <iostream>
using namespace std;
 
#define MKSTR( x ) #x
#define concat(a, b) a ## b

int main ()
{
    cout << MKSTR(HELLO C++) << endl;
    int xy = 100;
   
   cout << concat(x, y);
    cout << "Value of __LINE__ : " << __LINE__ << endl;
    cout << "Value of __FILE__ : " << __FILE__ << endl;
    cout << "Value of __DATE__ : " << __DATE__ << endl;
    cout << "Value of __TIME__ : " << __TIME__ << endl;
    
    return 0;
}

/*

当上面的代码被编译和执行时，它会产生下列结果：
HELLO C++
让我们来看看它是如何工作的。不难理解，C++ 预处理器把下面这行：
cout << MKSTR(HELLO C++) << endl;
转换成了：
cout << "HELLO C++" << endl;
## 运算符用于连接两个令牌。下面是一个实例：
#define CONCAT( x, y )  x ## y
当 CONCAT 出现在程序中时，它的参数会被连接起来，并用来取代宏。例如，程序中 CONCAT(HELLO, C++) 会被替换为 "HELLO C++"，如下面实例所示。
当上面的代码被编译和执行时，它会产生下列结果：

100
让我们来看看它是如何工作的。不难理解，C++ 预处理器把下面这行：

cout << concat(x, y);
转换成了：

cout << xy;
C++ 中的预定义宏
C++ 提供了下表所示的一些预定义宏：

宏	描述
__LINE__	这会在程序编译时包含当前行号。
__FILE__	这会在程序编译时包含当前文件名。
__DATE__	这会包含一个形式为 month/day/year 的字符串，它表示把源文件转换为目标代码的日期。
__TIME__	这会包含一个形式为 hour:minute:second 的字符串，它表示程序被编译的时间。
让我们看看上述这些宏的实例：

*/

