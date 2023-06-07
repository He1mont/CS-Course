#include <stdio.h>

void swap(int* arg1, int* arg2) // one frequent mistake
{                               // this function cannot swap 2 pointers
    int *value = NULL;          // 如果想要交换a和b的值，正确做法在Tu7
    value = arg1;               // 如果想要交换a和b的地址，正确做法在Tu9
    arg1 = arg2;                    
    arg2 = value;
}

int main(void)
{
    int a = 1;
    int b = 2;
    swap(&a, &b);
    printf("%d, %d\n", a, b);   // 1, 2

    return 0;
}