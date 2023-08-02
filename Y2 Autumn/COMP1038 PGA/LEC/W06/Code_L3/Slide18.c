// realloc to resize the previously allocated memory

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char *str;

    str = (char *) malloc(sizeof(char)*15);
    strcpy(str, "tutorialspoint");
    printf("String = %s, Address = %p\n", str, str);

    // str = (char *) realloc(str, sizeof(char)*25);
    strcat(str, ".com");
    printf("String = %s, Address = %p\n", str, str);

    // in the two prints, the addresses are the same

    free(str);
    return 0;
}