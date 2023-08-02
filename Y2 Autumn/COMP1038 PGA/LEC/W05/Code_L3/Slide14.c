// Iteration and Recursion
#include <stdio.h>

int factorial_iter(int x)
{
    if (x < 1){
        printf("Error, x < 1\n");
        exit(1);
    }

    int total = 1;
    int i = 0;
    for (i=x; i>1; i--){
        total = total * i;
    }

    return total;
}

int factorial_rec(int x)
{
    if (x < 1){
        printf("Error, x < 1\n");
        exit(1);
    }

    if (x == 1){
        return 1;
    } else {
        return factorial_rec(x-1) * x;
    }

    return total;
}
