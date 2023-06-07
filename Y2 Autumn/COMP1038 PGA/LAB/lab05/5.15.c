#include <stdio.h>
#include <math.h>

double hypo(double m, double n);

int main(void)      // 计算直角三角形的斜边长
{
    double m,n;
    printf("please enter the length of two sides: ");
    scanf("%lf %lf", &m, &n);

    double hy = hypo(m,n);
    printf("The Hypotenuse is %.3lf\n", hy);

    return 0;
}

double hypo(double m, double n)
{
    return sqrt(pow(m,2)+pow(n,2));
}