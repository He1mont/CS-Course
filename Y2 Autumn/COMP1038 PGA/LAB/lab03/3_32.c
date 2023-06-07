// Square of Asterisks
#include <stdio.h>

int main(void)
{
    int size;
    printf("type a number between 1-20:\n");
    scanf("%d", &size);

    int i,j;
    for (i=0; i<size; i++){
        for (j=0; j<size; j++){
            printf("* ");
        }
        printf("\n");
    }


    return 0;
}