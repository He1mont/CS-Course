#include <stdio.h>

int main(void)
{
    int *ptr;
    int a;
    ptr = &a;

    printf("%d, %d, %p\n", a, *ptr, ptr);

    return 0;
}