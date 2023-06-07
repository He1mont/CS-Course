#include <stdio.h>

void swap(int m, int n);

int main(void)
{
    int a = 1, b = 2;
    printf("%d %d\n", a, b);

    swap(a,b);

    printf("%d %d\n", a, b);

    return 0;
}

void swap(int m, int n)
{
    int t;
    t = m;
    m = n;
    n = t;
}