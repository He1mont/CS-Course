#include <stdio.h>

int main(void)  // Q2
{
    int *arr[3], i, p[3] = {10,20,30};

    for (i=0;i<3;i++){
        arr[i] = &p[i];
        printf("%d ", *arr[i]);
    }

    return 0;
}