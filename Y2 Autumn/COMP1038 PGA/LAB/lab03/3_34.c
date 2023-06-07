// Floyd's Triangle
#include <stdio.h>

int main(void)
{
    const int size = 10;
    int i,j;
    
    for (i=0; i<size; i++){
        for (j=0; j<=i; j++){
            int num = ((i+1)*(i+2))/2-(i-j);    // 可以int a = 1;
            printf("%d\t", num);                // 每次操作后 a++;
        }
        printf("\n");
    }


    return 0;
}