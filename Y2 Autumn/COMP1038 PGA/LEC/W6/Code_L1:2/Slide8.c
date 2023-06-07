#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char str[30] = "20.30300 this is test";
    char *ptr;
    double ret;

    ret = strtod(str, &ptr);
    printf("The number(double) is %f\n", ret);
    printf("String part is |%s|\n", ptr);   // 加｜｜是为了显示this前面的空格
                                            // 空格也被存进字符串里面了
    return 0;
}