#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
    char arr[100];
    char word[10];
    char tem[100];

    printf("Please type a line of text: \n");
    scanf("%[^\n]", arr);
    printf("Please give a word: ");
    scanf("%s", word);

    strcpy(tem,strstr(arr, word));
    printf("tem = %s\n", tem);

    strcpy(&tem[0], "\0");
    printf("tem = %s\n", tem);

    strcpy(tem,strstr(arr, word));
    printf("tem = %s\n", tem);

    strcpy(&tem[0], "\0");
    printf("tem = %s\n", tem);


    return 0;
}