#include <stdio.h>

int avg(float a, float b);          // Declaration

int main(int argc, char *argv[])    // slide 15
{
    printf("Outside function: %f\n\n", avg(4.9, 2.0));
    printf("Outside function: %d\n", avg(4.9, 2.0));

    return 0;
}

int avg(float a, float b)
{
    printf("Inside function: %f\n", (a/b));
    return (a/b);

}