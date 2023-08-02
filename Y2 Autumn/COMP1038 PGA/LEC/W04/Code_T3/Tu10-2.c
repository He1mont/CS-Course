/* Write a program in C to read a string (no more than 100 characters) 
 * then count how many spaces are contained
 * remove all spaces and print out the string in reverse order.
 */
#include <stdio.h>

int main(void)      // using pointer
{
    char str[101];
    char *ptr = str;
    printf("print a string of words: ")
    fgets(str, 100, stdin);

    int count = 0;
    int length = 0;
    int i = 0;

    while (*ptr!='\0'){
        if (*ptr == ' '){
            count ++;
        }
        ptr++;
        length++;
    }

    for (i=0;i<length;i++){
        if (str[length-1-i]!=' '){
            printf("%c", str[length-1-i]);
        }
    }
    printf("\nthere are %d spaces.\n", count);

    return 0;
}