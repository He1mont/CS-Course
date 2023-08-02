#include <stdio.h>

int main(void)
{
    int input = 0;
    int sum = 0;

    /* 如果一次性输入1 2，程序会输出3
       如果一次性输入1 2 3 4，程序还是会输出3 */

    printf("Please enter an input:");
    scanf("%d", &input);

    sum = sum + input;

    printf("Please enter an input:");
    scanf("%d", &input);

    sum = sum + input;

    printf("The sum of two numbers is %d\n", sum);

    return 0;
}