#include <stdio.h>
#include "calculator.h"

int main(void)
{
    printf("1 + 2 = %2d\n", addInt(1,2));
    printf("1 - 2 = %2d\n", subInt(1,2));
    printf("1 * 2 = %2d\n", multiInt(1,2));
    printf("1 / 2 = %2d\n", divInt(1,2));

    return 0;
}