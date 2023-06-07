#include <stdio.h>

int iter(int n);
int recur(int n);

int main(void)      // 求斐波那契数列第n项
{
    int n;
    printf("Please enter your number n: ");
    scanf("%d", &n);

    printf("The nth number in Fibo Array is %d\n", iter(n));
    printf("The nth number in Fibo Array is %d\n", recur(n));
    
    return 0;
}

int iter(int n)
{
    int a = 0, b = 1;
    int ret;
    if (n == 1){
        return a;
    } else if (n == 2){
        return b;
    } else {
        while (n >= 3){
            ret = a + b;
            a = b, b = ret;
            n--;
        }
    }
    return ret;
}

int recur(int n)
{
    if (n == 1){
        return 0;
    } else if (n == 2) {
        return 1;
    } else {
        return recur(n-1) + recur(n-2);
    }
}