#include <stdio.h>

long expo(int base,int n);

int main(void)      // 递归函数求幂方
{
    int base, n;
    printf("please enter your base and n: ");
    scanf("%d %d", &base, &n);

    printf("%d %d\n", base, n);

    if (n < 0){
        printf("n should be a natural number!\n");
    } else {
        printf("The base to the time of n is: %ld", expo(base, n));
    }
    return 0;
}

long expo(int base, int n)
{
    if (n == 0) {
        return 1;
    } else {
        return base * expo(base, n-1);
    }
}