#include <stdio.h>

int main(void)  // Q2
{
    char *arr[3];
    int i,j;
    arr[0] = "This is";
    arr[1] = "a new";
    arr[2] = "message";

    // print out the string and the 1st character
    for (i=0;i<3;i++){
        printf("Text: %s\tFirst char: %c\n",arr[i], *arr[i] );
    }
    printf("\n");

    // print out the second character
    for (i=0;i<3;i++){
        printf("Second char: %c\n", *(arr[i]+1));
    }

    return 0;
}