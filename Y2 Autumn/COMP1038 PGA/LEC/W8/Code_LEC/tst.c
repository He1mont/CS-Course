#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    int sizelen = 20;

    char *new_name = (char*)malloc(sizeof(char)*sizelen);
    char *new_pNum = (char*)malloc(sizeof(char)*sizelen);
    char *new_email = (char*)malloc(sizeof(char)*sizelen);
    char *new_dep = (char*)malloc(sizeof(char)*sizelen);

    char c;
    char *ptr;

    printf("Name: ");
    scanf("%s", ptr);
    while ((c=getchar()) != '\n' && c != EOF);

    while (strlen(ptr) > sizelen){
        sizelen++;
    }

    printf("strlen = %ld\n", strlen(new_name));
    printf("sizelen = %d\n", sizelen);

    new_name = (char*)realloc(new_name, sizeof(char)*sizelen);
    strcpy(new_name ptr);


    printf("Number: ");
    scanf("%s", new_pNum);
    while ((c=getchar()) != '\n' && c != EOF);

    printf("Email: ");
    scanf("%s", new_email);
    while ((c=getchar()) != '\n' && c != EOF);

    printf("Department: ");
    scanf("%s", new_dep);
    while ((c=getchar()) != '\n' && c != EOF);

    printf("%s\n%s\n%s\n%s\n", 
        new_name, new_pNum, new_email, new_dep);

    free(new_name);
    free(new_pNum);
    free(new_email);
    free(new_dep);

    return 0;
}