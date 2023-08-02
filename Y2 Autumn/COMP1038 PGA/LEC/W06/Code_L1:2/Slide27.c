#include <stdio.h> 
#include <string.h>

int main (void) {

    const char str[] = "http://www.tutotialspoint.com";
    const char ch = '.';
    char *ret;

    ret = strchr(str, ch);
    printf("String after |%c| is |%s|\n", ch, ret);

    ret = strrchr(str, ch);
    printf("String after |%c| is |%s|\n", ch, ret);

    return 0;
}