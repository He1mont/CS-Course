#include <stdio.h>
#include <stdlib.h>

char *prompt(const char *mesg, const int limit);

int main(int argc, char *argv[])
{
    char *name = prompt("Who are you?\n", 20);
    if (name == NULL){
        printf("Error! \n");
    } else {
        printf("Hello %s!\n", name);
        free(name);
    }

    return 0;
}

char *prompt(const char *mesg, const int limit)
{
    char *name;
    name = malloc(sizeof(char) * (limit+1));    // 多一位用来储存'\0'

    if(name == NULL){
        return NULL;
    }

    printf("%s", mesg);
    scanf("%s", name);

    return name;
}