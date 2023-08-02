#include <stdio.h>

int main(void)  // Question 6
{
    int *ptr1, *ptr2, *ptr3;
    int i=10, j=20, k=30;

    ptr1 = &i;
    ptr2 = &j;
    ptr3 = &k;

    *ptr1 = *ptr2 = *ptr3;
    k = i + j;

    printf("%d\n", *ptr3 );

    return 0;
}