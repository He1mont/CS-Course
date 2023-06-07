/* Write a program in C to read a string (no more than 100 characters) 
 * then count how many spaces are contained
 * remove all spaces and print out the string in reverse order.
 */
#include <stdio.h>

int main(void)      // using array
{
    char str[100];
    char newstr[100];

    // initialization
    int i;
    for (i = 0; i < 100; i++){
        str[i] = 0;
    }

    // input
    printf("please type a string less than 100 characters: ");
    scanf("%[^\n]", str);

    // get out the space and count the space
    int len = 0, cnt = 0;
    for (i=0;i<100;i++){
        if (str[i] == 0){
            break;          
        }else if (str[i] == 32){
            cnt = cnt + 1;
        }else {
            newstr[len] = str[i];
            len++;
        }
    }

    // print out in deverse order
    for (i=len-1;i>=0;i--){
        printf("%c", newstr[i]);
    }

    printf("\nthere are %d spaces.\n", cnt);

    return 0;
}