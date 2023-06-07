#include <stdio.h>

int main(void)
{
    int a = 1;
    int b =2;

    int *p1 = &a;
    int *p2 = &b;
    printf("%d, %d\n", *p1, *p2);

    p1 = p2;    // p1 points to what p2 point2, so p1 points to b
    *p1 = 3;    // p1 and p2 both points to b
    printf("%d, %d\n", a, b);
    printf("%d, %d\n", *p1, *p2);

    return 0;
}