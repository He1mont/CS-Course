#include <stdio.h>

int main(void)
{
    int x = 5;
    int *p = NULL;

    p = &x;

    printf("*p is %d\n", *p);
    // printf("p is %d\n", p);      // 如果用%d输出指针会有乱码

    printf("p is %p\n", p);
    printf("x is %d\n", x);

    *p = 7;
    printf("\n\nde-p is %d\n", *p); 
    printf("p is %p\n", p);         // p所指向的地址不会改变
    printf("x is %d\n", x);         // 修改*p，那么p所指的x的值也会被修改

    return 0;
}