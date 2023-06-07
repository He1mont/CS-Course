#include <stdio.h> 
#include <string.h>

int main (void)
{
    int i;
    char str1[] = "12t9h8";
    char str2[] = "t1234567890";

    i = strspn(str1, str2);

    printf("The initial number has %d digits.\n", i);

    return 0;
}