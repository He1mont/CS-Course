#include <stdio.h>
#include <stdlib.h>

int max(int a, int b);

int main(int argc, char *argv[])
{
    int x = 3;
    int y = 4;
    int m = max(x,y);
    printf("Between %d and %d, max is %d\n", x, y, m);

    return 0;
}

int max(int a, int b)
{
    if (a > b){

        printf("a is %d, and b is %d\n", a, b);
        a = 1, b = 2;
        printf("a is %d, and b is %d\n", a, b);

        return a;
    }else{

        printf("a is %d, and b is %d\n", a, b);
        a = 5, b = 6;
        printf("a is %d, and b is %d\n", a, b);

        return b;
    }
}
