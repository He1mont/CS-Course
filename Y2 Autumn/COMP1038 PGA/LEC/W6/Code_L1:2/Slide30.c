#include <stdio.h> 
#include <string.h>

int main (void) 
{
    char s1[] = "GeeksforGeeks";
    char s2[] = "for";
    char *p;

    p = strstr(s1,s2);

    if (p) {
        printf("String found!\n");
        printf("First occurence of string '%s' in '%s' is '%s'\n\n", s2, s1, p);
    } else {
        printf("String not found :(\n");
    }

    const char haystack[20] = "TutorialsPoint";
    const char needle[10] = "Point";
    char *ret;

    ret = strstr(haystack, needle);
    printf("the substring is: %s\n", ret);


    return 0;
}