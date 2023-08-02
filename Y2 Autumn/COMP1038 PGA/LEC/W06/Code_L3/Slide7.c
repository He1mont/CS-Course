#include <stdio.h>

int global;                 // global variable

int main(void)
{
    static int i = 100;     // static int，能让在函数内定义的变量成为全局变量
    static int j;

    int k;

    printf("%p\n", &k);
    printf("%p\n", &global);// the address of uninitialized data is higher
    printf("%p\n", &i);
    printf("%p\n", &j);
    printf("%p\n", main);   // main is a name of a function, and is an address
                            // the code is in address "text"
    return 0;
}