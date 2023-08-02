#include <stdio.h>

//  If条件的三种实现
int main(void)
{
    int A = 10;
    int B = 20;
    int C = 0;

    // if-else statement
    if (A > B){
        C = A - B;
    } else {
        C = B - A;
    }
    printf("The difference between A and B is %d\n", C);

    // Conditional operator
    (A > B) ? (C = A - B) : (C = B - A);
    printf("The difference between A and B is %d\n", C);

    // Switch Statement
    C = A - B;
    switch ((int) (C >= 0))
    {
    case 0: // C >= 0 is False
        printf("The difference between A and B is %d\n", C*(-1));
        break;
    case 1: // C >= 0 is True
        printf("The difference between A and B is %d\n", C);
        break;
    default:
        printf("Error!!\n");
        break;
    }

    return 0;
}