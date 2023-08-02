#include <stdio.h>

int main(void)
{
    int *px = NULL;

    printf("%d, %p", *px, px);  // segmentation fault

    return 0;
}