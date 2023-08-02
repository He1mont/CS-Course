#include <stdio.h>

int main(void)
{
    int i = 10, j = 20;
    int *ptr1 = &i, *ptr2 = &j;

    *ptr2 = *ptr1;
    printf("*ptr1 = %d\n", *ptr1);
    printf("*ptr2 = %d\n", *ptr2);
    printf("The address is %p\n", ptr1);
    printf("The address is %p\n\n", ptr2);
    
    i = 10; j = 20;
    ptr2 = ptr1;
    printf("*ptr1 = %d\n", *ptr1);
    printf("*ptr2 = %d\n", *ptr2);
    printf("The address is %p\n", ptr1);
    printf("The address is %p\n\n", ptr2);


    return 0;
}