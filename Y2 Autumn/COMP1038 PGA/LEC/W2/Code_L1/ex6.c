#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int x, y, z;

    printf("Enter value for x:\n");
    scanf("%d", &x);
    if (x<1) {
        printf("Invalid value\n");
        exit(1);
    }

    printf("Enter value for y:\n");
    scanf("%d", &y);
    if (y<1) {
        printf("Invalid value\n");
        exit(1);
    }

    printf("Enter value for z\n:");
    scanf("%d", &z);
    if (z<1) {
        printf("Invalid value\n");
        exit(1);
    }

    int lhs = x*x + y*y;
    int rhs = z*z;

    if (lhs == rhs){
        printf("Right angled triangle\n");
    } else {
        printf("Not right angled, %d does not equal %d\n", lhs, rhs);
    }

    return 0;
}