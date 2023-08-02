#include <stdio.h> 
#include <string.h>

int main (void) {

    char leftStr[] = "g f g";
    char rightStr[] = "g f g";

    int res = strcmp(leftStr, rightStr);

    if (res == 0){
        printf("Strings are equal");
    } else {
        printf("Strings are not equal");
    }

    printf("\nValue return by strcmp() is %d\n\n", res);

    char str1[15];
    char str2[15];
    int ret;

    strcpy(str1,"abcdef");
    strcpy(str2,"abcdpqrs");
    
    ret = strncmp(str1, str2, 4);

    if (res == 0){
        printf("4 first characters of str1 and str2 are equal");
    } else {
        printf("4 first characters of str1 and str2 are not equal");
    }

    return 0;

}