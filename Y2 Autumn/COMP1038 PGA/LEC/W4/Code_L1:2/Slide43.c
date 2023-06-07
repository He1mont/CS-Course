#include <stdio.h>

int main(void)
{
    int *ptr, i, arr[5] = {1,2,3,4,5};
    ptr = arr;

    // This means that array name is a pointer
    // arr == &arr == &arr[0]
    printf("%p, %d, %p, %p\n", ptr, *ptr, arr, &arr);
    printf("\n");

    for (i=0; i<5; i++){
        printf("Addr = %p, Val = %d\n", ptr, *ptr);
        ptr++;  // it means that the ptr go to the next location
                // does not mean that the byte plus 1
                // it can also be written as *(ptr+1), NOT *ptr+1 !! 
    }

    return 0;
}