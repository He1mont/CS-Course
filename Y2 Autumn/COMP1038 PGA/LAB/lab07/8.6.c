// Write a program that inputs a line of text into char array s[100]. 
// Output the line in alternate uppercase letters and lowercase letters.

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    char str[100];
    char upper[100];
    char lower[100];

    // initialization
    int i;
    for (i=0; i<100; i++){
        str[i] = '\0';
    }

    printf("Please type a line of text less than 100 characters: \n");
    scanf("%s", str);

    i = 0;
    while (str[i] != '\0'){
        if (islower(str[i])){
            lower[i] = str[i];
            upper[i] = toupper(str[i]);
        } else if(isupper(str[i])){
            upper[i] = str[i];
            lower[i] = tolower(str[i]);
        }
        i++;
    }

    printf("\nThe original one is: \n%s\n\n", str);
    printf("The UPPER case is: \n%s\n\n", upper);
    printf("The lower case is: \n%s\n\n", lower);


    return 0;
}