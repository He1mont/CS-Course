// Hollow Square of Asterisks
#include <stdio.h>

int main(void)
{
    int size;
    printf("type a number between 1-20:");
    scanf("%d", &size);

    int i,j;
    for (i=0; i<size; i++){
        for (j=0; j<size; j++){
            if(((i>=1)&&(i<=size-2))&&((j>=1)&&(j<=size-2))){
                printf("  ");
            } else {
                printf("* ");
            }
        }
        printf("\n");
    }

    return 0;
}