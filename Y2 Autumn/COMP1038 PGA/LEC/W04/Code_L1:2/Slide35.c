#include <stdio.h>

int main(void)
{
    int x = 5, y = 6;
    int *const p = &x;

    printf("%d ", x);
    printf("%d\n", *p);

    x = 7;
    printf("%d ", x);
    printf("%d\n", *p);

    *p = 9;         // Not allowed?
    printf("%d ", x);
    printf("%d\n", *p);

    *p = y;         // 只是把y的值赋给*p   
    printf("%d ", x);
    printf("%d ", y);
    printf("%d\n", *p);

    // p = &y;         // 不被允许的
    // printf("%d ", x);
    // printf("%d ", y);
    // printf("%d\n", *p);

    return 0;
}