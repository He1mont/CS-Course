// 直角三角形的第三条边
#include <stdio.h>
#include <math.h>

int main(void)
{
    float a,b;

    printf("Enter a float:");
    scanf("%f", &a);
    printf("Enter a float:");
    scanf("%f", &b);

    float c = sqrt(pow(a,2) + pow(b,2));

    printf("The length of the longest side is: %f", c);
    

    return 0;
}