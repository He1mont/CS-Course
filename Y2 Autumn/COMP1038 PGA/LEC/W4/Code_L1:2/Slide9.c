#include <stdio.h>

int main(void)
{
    int Y = 1;
    int *Yptr;
    Yptr = &Y;
    
    printf("%d\n", Y);
    printf("%d\n", *Yptr);

    printf("\n");

    printf("%p\n", &Y);
    printf("%p\n", Yptr);

    printf("\n");

    // * and & are complements of each other
    printf("%p\n", &*Yptr); // &和*哪个在前面都可以
    printf("%p\n", *&Yptr);
    printf("%p\n", &Yptr);

    printf("\n");

    // size of a pointer
    printf("%lu\n", sizeof(Yptr));  // 8
    printf("%lu\n", sizeof(4));     // 4


    return 0;
}