// display a text-based menu
#include <stdio.h>
#include <string.h>

int main(void)
{
    int ans = 0;
    do{
        printf("Option 1 should ask for 2 numbers and add them.\n");
        printf("Option 2 should ask for 2 numbers and multiply them.\n");
        printf("Option 3 should ask for 2 numbers and calculate the modulus.\n");
        printf("Option 4 should exit the program.\n");

        // ask for option
        int opt = 0;
        printf("please leave your option:");
        scanf("%d", &opt);

        int a,b;

        // execute the option
        switch (opt)
        {
        case 1:
            scanf("%d %d", &a, &b);
            printf("the sum is %d\n", a+b);
            break;

        case 2:
            scanf("%d %d", &a, &b);
            printf("the multiplation is %d\n", a*b);
            break;    

        case 3:
            scanf("%d %d", &a, &b);
            printf("the modulus is %d\n", a%b);
            break;   

        default:
            printf("Wrong number, Bitch!\n");
            break;
        }

        // ask for another game
        printf("Do you wanna play again? Type 1 as YES: ");
        scanf("%d", &ans);
        printf("\n");

    }while(ans == 1);
    
    return 0;
}