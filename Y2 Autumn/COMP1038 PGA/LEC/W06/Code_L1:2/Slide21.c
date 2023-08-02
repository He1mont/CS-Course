#include <stdio.h> 
#include <string.h>

int main (void) {

    char str1[100] = "This is", str2[] = "programiz.com";

    // concatenates str1 and str2
    strcat(str1, str2);     // the resultant string is stored in str1

    puts(str1);
    puts(str2);

    char dest[50] = "abcd";
    char src[50] = "efghijkl";

    strncat(dest, src, 5);

    printf("Destination string: %s\n", dest);
    printf("Source string: %s\n", src);

    return 0;

}