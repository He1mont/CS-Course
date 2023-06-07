#include <stdio.h>

int main(void)  // Quetion 2
{
    int *pc, c;
    c = 5;
    pc = &c;
    c = 1;

    printf("%d ", c);
    printf("%d ", *pc);

    return 0;
}