#include <stdio.h> 
#include <string.h>

int main (void) {

    char src[] = "geeksforgeeks";

    char str[20];
    char dest[14];      // dest stands for destination
    char *ptr = str;

    // copying src into dest.
    strcpy(dest, src);
    strcpy(ptr, src);

    printf("Copied string: %s\n", dest);
    printf("Copied string: %s\n", ptr);

    strncpy(dest, src, 8);  // Length of destination string: 8

    int len = strlen(dest);

    printf("Copied string: %s\n", dest);
    printf("Length of destination string: %d\n", len);

    return 0;

}