#include <stdio.h>

int main(void)
{
    const int x = 5, y = 6;

    // Case 1:
    int *p = &x;        // *p的值可以改变，但x的值不会被改变，因此造成loop hole

    // Case 2: 
    const int *p = &x;  // *p的值不会被改变，*p = 7会报错

    // Case 3:
    int *const p = &x;  // p只能指向x，不能指向y

    // Case 4:          
    int x = 5;          // x和*p的值都可以被改变(?) Slide 35
    int *const p = &x;  // 但p只能指向x，不能指向别的变量

    printf("de-p is %d\n", *p);
    printf("x is %d\n", x);
    printf("y is %d\n", y);

    // x = 7;
    *p = 7;
    printf("\n\nde-p is %d\n", *p);
    printf("x is %d\n", x);
    printf("y is %d\n", y);

    p = &y;
    printf("\n\nde-p is %d\n", *p);
    printf("x is %d\n", x);
    printf("y is %d\n", y);



    return 0;
}