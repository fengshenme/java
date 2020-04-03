/*

C++ 判断
判断结构要求程序员指定一个或多个要评估或测试的条件，以及条件为真时要执行的语句（必需的）和条件为假时要执行的语句（可选的）。
下面是大多数编程语言中典型的判断结构的一般形式：
C++ 中的判断语句
判断语句
C++ 编程语言提供了以下类型的判断语句。点击链接查看每个语句的细节。
语句	描述
if 语句	一个 if 语句 由一个布尔表达式后跟一个或多个语句组成。
if...else 语句	一个 if 语句 后可跟一个可选的 else 语句，else 语句在布尔表达式为假时执行。
嵌套 if 语句	您可以在一个 if 或 else if 语句内使用另一个 if 或 else if 语句。
switch 语句	一个 switch 语句允许测试一个变量等于多个值时的情况。
嵌套 switch 语句	您可以在一个 switch 语句内使用另一个 switch 语句。
? : 运算符
我们已经在前面的章节中讲解了 条件运算符 ? :，可以用来替代 if...else 语句。它的一般形式如下：
Exp1 ? Exp2 : Exp3;
其中，Exp1、Exp2 和 Exp3 是表达式。请注意，冒号的使用和位置。
? 表达式的值是由 Exp1 决定的。如果 Exp1 为真，则计算 Exp2 的值，结果即为整个 ? 表达式的值。
如果 Exp1 为假，则计算 Exp3 的值，结果即为整个 ? 表达式的值。

*/
#include <iostream>
using namespace std;
void ifa(void);
void ifelse(void);
void ifelseif(void);
void nestif(void);
void switcha(void);
void nestswitch(void);

int main(){

    ifa();
    ifelse();
    ifelseif();
    nestif();
    switcha();
    nestswitch();
    return 0;

}

/*

一个 if 语句 由一个布尔表达式后跟一个或多个语句组成。
C++ 中 if 语句的语法：
if(boolean_expression)
{
   // 如果布尔表达式为真将执行的语句
}
如果布尔表达式为 true，则 if 语句内的代码块将被执行。如果布尔表达式为 false，则 if 语句结束后的第一组代码（闭括号后）将被执行。
C 语言把任何非零和非空的值假定为 true，把零或 null 假定为 false。
C++ 中的 if 语句
实例
*/

void ifa(){
    // 局部变量声明
   int a = 10;
 
   // 使用 if 语句检查布尔条件
   if( a < 20 )
   {
       // 如果条件为真，则输出下面的语句
       cout << "a 小于 20" << endl;
   }
   cout << "a 的值是 " << a << endl;
}

/*

C++ if...else 语句
C++ 判断 C++ 判断
一个 if 语句 后可跟一个可选的 else 语句，else 语句在布尔表达式为假时执行。
语法
C++ 中 if...else 语句的语法：
if(boolean_expression)
{
   // 如果布尔表达式为真将执行的语句
}
else
{
   // 如果布尔表达式为假将执行的语句
}
如果布尔表达式为 true，则执行 if 块内的代码。如果布尔表达式为 false，则执行 else 块内的代码。
流程图
C++ 中的 if...else 语句

*/
void ifelse(){
       // 局部变量声明
   int a = 100;
 
   // 检查布尔条件
   if( a < 20 )
   {
       // 如果条件为真，则输出下面的语句
       cout << "a 小于 20" << endl;
   }
   else
   {
       // 如果条件为假，则输出下面的语句
       cout << "a 大于 20" << endl;
   }
   cout << "a 的值是 " << a << endl;
}

/*
f...else if...else 语句
一个 if 语句后可跟一个可选的 else if...else 语句，这可用于测试多种条件。

当使用 if...else if...else 语句时，以下几点需要注意：

一个 if 后可跟零个或一个 else，else 必须在所有 else if 之后。
一个 if 后可跟零个或多个 else if，else if 必须在 else 之前。
一旦某个 else if 匹配成功，其他的 else if 或 else 将不会被测试。
语法
C++ 中的 if...else if...else 语句的语法：

if(boolean_expression 1)
{
   // 当布尔表达式 1 为真时执行
}
else if( boolean_expression 2)
{
   // 当布尔表达式 2 为真时执行
}
else if( boolean_expression 3)
{
   // 当布尔表达式 3 为真时执行
}
else 
{
   // 当上面条件都不为真时执行
}
实例
*/
void ifelseif(){

    // 局部变量声明
   int a = 100;
 
   // 检查布尔条件
   if( a == 10 )
   {
       // 如果 if 条件为真，则输出下面的语句
       cout << "a 的值是 10" << endl;
   }
   else if( a == 20 )
   {
       // 如果 else if 条件为真，则输出下面的语句
       cout << "a 的值是 20" << endl;
   }
   else if( a == 30 )
   {
       // 如果 else if 条件为真，则输出下面的语句
       cout << "a 的值是 30" << endl;
   }
   else
   {
       // 如果上面条件都不为真，则输出下面的语句
       cout << "没有匹配的值" << endl;
   }
   cout << "a 的准确值是 " << a << endl;

}

/*
C++ 嵌套 if 语句
C++ 判断 C++ 判断

在 C++ 中，嵌套 if-else 语句是合法的，这意味着您可以在一个 if 或 else if 语句内使用另一个 if 或 else if 语句。

语法
C++ 中 嵌套 if 语句的语法：

if( boolean_expression 1)
{
   // 当布尔表达式 1 为真时执行
   if(boolean_expression 2)
   {
      // 当布尔表达式 2 为真时执行
   }
}
您可以嵌套 else if...else，方式与嵌套 if 语句相似。
*/
void nestif(){
    // 局部变量声明
   int a = 100;
   int b = 200;
 
   // 检查布尔条件
   if( a == 100 )
   {
       // 如果条件为真，则检查下面的条件
       if( b == 200 )
       {
          // 如果条件为真，则输出下面的语句
          cout << "a 的值是 100，且 b 的值是 200" << endl;
       }
   }
   cout << "a 的准确值是 " << a << endl;
   cout << "b 的准确值是 " << b << endl;
 
}

/*
C++ switch 语句
C++ 判断 C++ 判断

一个 switch 语句允许测试一个变量等于多个值时的情况。每个值称为一个 case，且被测试的变量会对每个 switch case 进行检查。

语法
C++ 中 switch 语句的语法：

switch(expression){
    case constant-expression  :
       statement(s);
       break; // 可选的
    case constant-expression  :
       statement(s);
       break; // 可选的
  
    // 您可以有任意数量的 case 语句
    default : // 可选的
       statement(s);
}
switch 语句必须遵循下面的规则：

switch 语句中的 expression 必须是一个整型或枚举类型，或者是一个 class 类型，其中 class 有一个单一的转换函数将其转换为整型或枚举类型。
在一个 switch 中可以有任意数量的 case 语句。每个 case 后跟一个要比较的值和一个冒号。
case 的 constant-expression 必须与 switch 中的变量具有相同的数据类型，且必须是一个常量或字面量。
当被测试的变量等于 case 中的常量时，case 后跟的语句将被执行，直到遇到 break 语句为止。
当遇到 break 语句时，switch 终止，控制流将跳转到 switch 语句后的下一行。
不是每一个 case 都需要包含 break。如果 case 语句不包含 break，控制流将会 继续 后续的 case，直到遇到 break 为止。
一个 switch 语句可以有一个可选的 default case，出现在 switch 的结尾。default case 可用于在上面所有 case 都不为真时执行一个任务。default case 中的 break 语句不是必需的。
流程图
C++ 中的 switch 语句
实例
*/
void switcha(){
    // 局部变量声明
   char grade = 'D';
 
   switch(grade)
   {
   case 'A' :
      cout << "很棒！" << endl; 
      break;
   case 'B' :
   case 'C' :
      cout << "做得好" << endl;
      break;
   case 'D' :
      cout << "您通过了" << endl;
      break;
   case 'F' :
      cout << "最好再试一下" << endl;
      break;
   default :
      cout << "无效的成绩" << endl;
   }
   cout << "您的成绩是 " << grade << endl;

}

/*
C++ 嵌套 switch 语句
C++ 判断 C++ 判断

您可以把一个 switch 作为一个外部 switch 的语句序列的一部分，即可以在一个 switch 语句内使用另一个 switch 语句。即使内部和外部 switch 的 case 常量包含共同的值，也没有矛盾。

C++ 中的 switch 语句允许至少 256 个嵌套层次。

语法
C++ 中 嵌套 switch 语句的语法：

switch(ch1) {
   case 'A': 
      cout << "这个 A 是外部 switch 的一部分";
      switch(ch2) {
         case 'A':
            cout << "这个 A 是内部 switch 的一部分";
            break;
         case 'B': // 内部 B case 代码
      }
      break;
   case 'B': // 外部 B case 代码
}
*/
void nestswitch(){
    // 局部变量声明
   int a = 100;
   int b = 200;
 
   switch(a) {
      case 100: 
         cout << "这是外部 switch 的一部分" << endl;
         switch(b) {
            case 200:
               cout << "这是内部 switch 的一部分" << endl;
         }
   }
   cout << "a 的准确值是 " << a << endl;
   cout << "b 的准确值是 " << b << endl;

}