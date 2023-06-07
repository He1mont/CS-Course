#include <stdio.h>

int global;                 // global variable

int main(void)
{
    static int i = 100;     // static int，能让在函数内定义的变量成为全局变量
    static int j;

    int k;

    int *p = malloc(sizeof(int));   // malloc: memory allocation

    printf("%p\n", &k);
    printf("%p\n", &p);
    printf("%p\n", &global);// the address of uninitialized data is higher
    printf("%p\n", &i);
    printf("%p\n", &j);
    printf("%p\n", main);   // main is a name of a function, and is an address
                            // the code is in address "text"
    free(p);    // to release the memory
    
    return 0;
}