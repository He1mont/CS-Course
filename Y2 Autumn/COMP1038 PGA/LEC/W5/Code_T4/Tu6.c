#include <stdio.h>

int func(int arg1, int arg2)            // pass by value
{
    arg1 = arg1 + arg2;
    return arg1;
}

int main(void)
{
    int a = 1;
    int b = 2;
    int c = func(a,b);
    printf("%d, %d, %d\n", a, b, c);    // 1, 2, 3
                                        // a的值不会被改变
    return 0;
}