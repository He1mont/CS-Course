// Pass by Value VS Pass by Reference
#include <stdio.h>

// // Pass by Value 
// int add(int a);     

// int main(void)
// {
//     int b = 2;
//     printf("b = %d, return value from add() is %d\n", b, add(b));

//     return 0;
// }

// int add(int a)
// {
//     return (++a);
// }


// Pass by Reference
int add(int *a);     

int main(void)
{
    int b = 2;
    printf("b = %d, return value from add() is %d\n", b, add(&b));

    return 0;
}

int add(int *a)
{
    return (++(*a));    //区别于*(a++)，*a++ is confusing
}