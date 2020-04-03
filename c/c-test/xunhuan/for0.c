/*
循环类型
C 语言提供了以下几种循环类型。点击链接查看每个类型的细节。
循环类型	描述
while 循环	当给定条件为真时，重复语句或语句组。它会在执行循环主体之前测试条件。
for 循环	多次执行一个语句序列，简化管理循环变量的代码。
do...while 循环	除了它是在循环主体结尾测试条件外，其他与 while 语句类似。
嵌套循环	您可以在 while、for 或 do..while 循环内使用一个或多个循环。
循环控制语句
循环控制语句改变你代码的执行顺序。通过它你可以实现代码的跳转。
C 提供了下列的循环控制语句。点击链接查看每个语句的细节。

控制语句	描述
break 语句	终止循环或 switch 语句，程序流将继续执行紧接着循环或 switch 的下一条语句。
continue 语句	告诉一个循环体立刻停止本次循环迭代，重新开始下次循环迭代。
goto 语句	将控制转移到被标记的语句。但是不建议在程序中使用 goto 语句。

无限循环
如果条件永远不为假，则循环将变成无限循环。
for 循环在传统意义上可用于实现无限循环。由于构成循环的三个表达式中任何一个都不是必需的，
您可以将某些条件表达式留空来构成一个无限循环。
*/


#include <stdio.h>
 
int main ()
{
   for( ; ; )
   {
      printf("该循环会永远执行下去！\n");
   }
   return 0;
}