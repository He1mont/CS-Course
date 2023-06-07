#include <stdio.h>
#include <stdlib.h>

int max(int a, int b);              // Declaration

int main(int argc, char *argv[])    // slide 11
{
    if (argc == 3){
        printf("Max value between %s and %s is: ", argv[1], argv[2]);
        printf("%d\n", max(atoi(argv[1]), atoi(argv[2])));
    }

    return 0;
}

int max(int a, int b)
{
    if (a > b){
        return a;
    } else {
        return b;
    }

}