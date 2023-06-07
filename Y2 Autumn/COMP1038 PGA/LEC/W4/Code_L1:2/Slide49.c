#include <stdio.h>

int main(void)  // Question 8
{
    int *ptr, arr[5] = {10,20,30,40,50};
    ptr = arr;

    printf("Val1 = %d, Val2 = %d\n", *ptr+2, *(ptr+2));

    return 0;
}