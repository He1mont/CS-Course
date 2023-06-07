#include <stdio.h>
#include <math.h>

int main(void)
{
    double amount;
    double principal = 1000.0;
    double rate = 0.05;
    unsigned int year;

    // %4s中，4表示这个变量需要占用4个字符的位置，s表示输出的是字符串类型
    // 如果最终显示出来的数值个数小于域宽则数据将自动的在域宽内向右对齐
    // 如果想让数据在域宽内向左对齐，可以在转换说明符中的%与域宽定义值之间加上一个减号(－)
    printf("%4s%21s\n", "Year", "Amount on deposit");

    for (year = 1; year <= 10; year++){
        amount = principal * pow(1.0+rate, year);

    // %4u中，u表示输出的是year是unsigned int类型，%d也是可以成功运行的
    // %21.2f中，21表示这个变量需要占用21个字符的位置
    //          f表示输出浮点数，.2表示保留2位小数（默认保留6位）
        printf("%4u%21.2f\n", year, amount);
    }

    return 0;
}