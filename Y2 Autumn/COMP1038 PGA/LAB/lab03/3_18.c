// Sales-Commission Calculator
#include <stdio.h>

int main(void)
{
    float m = 0;
    printf("Enter sales in dollars (-1 to end): \n");
    scanf("%f", &m);

    while (m != -1){
        float sal = m*0.09 + 200;
        printf("Salary is $%.2f\n", sal);

        // decide whether to enter the loop again
        printf("Enter sales in dollars (-1 to end): ");
        scanf("%f", &m);
    }

    return 0;
}