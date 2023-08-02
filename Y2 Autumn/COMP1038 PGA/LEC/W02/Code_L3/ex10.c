#include <stdio.h>

int main(void)
{
    int keepGoing =1;

    do{
        printf("1) Add\n");
        printf("2) Multiply\n");
        printf("3) Mod\n");
        printf("4) Quit\n");
        printf("Enter option:");

        int option = 0;
        scanf("%d", &option);

        if (option ==1){
            int n1 = 0;
            printf("Enter the first number:");
            scanf("%d", &n1);

            int n2 = 0;
            printf("Enter the second number:");
            scanf("%d", &n2);

            int ans = n1 + n2;
            printf("The answer is %d\n\n", ans);
        } else if(option == 2){
            int n1 = 0;
            printf("Enter the first number:");
            scanf("%d", &n1);

            int n2 = 0;
            printf("Enter the second number:");
            scanf("%d", &n2);

            int ans = n1 * n2;
            printf("The answer is %d\n\n", ans);
        } else if(option == 3){
            int n1 = 0;
            printf("Enter the first number:");
            scanf("%d", &n1);

            int n2 = 0;
            printf("Enter the second number:");
            scanf("%d", &n2);

            int ans = n1 % n2;
            printf("The answer is %d\n\n", ans);
        } else if(option == 4){
            keepGoing = 0;
        }
    } while (keepGoing);

    return 0;
}
