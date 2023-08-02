#include <stdio.h>

int main(void)  // Q2
{
    int *ptr, i;

    ptr = &i;
    printf("Address = %p\n", ptr);
    
    ptr -= 10;
    printf("Address = %p\n", ptr);

    return 0;
}