#include <stdio.h>

void even(int n);

int main(void)      // 判断一个数是否是偶数
{
    int n;
    printf("please type your first number (-1 to quit): ");
    scanf("%d",&n);

    while (n != -1){
        even(n);
        printf("Please typer another number (-1 to quit): ");
        scanf("%d",&n);
    }

    printf("The game is Over!");

    return 0;
}

void even(int n)
{
    if (n % 2 == 0){
        printf("This number is even! \n");
    } else{
        printf("This number is odd!\n");
    }
}