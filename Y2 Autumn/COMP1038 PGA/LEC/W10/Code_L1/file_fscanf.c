#include <stdio.h>

int main() 
{
    FILE *fp;
    char buff[255];
    fp = fopen("./tmp/test.txt", "r");

    if(fp == NULL)
    {
        printf("File does not exist\n");
        return 1;
    }
    
    fscanf(fp, "%s", buff);
    printf("%s\n", buff );
    fclose(fp);

return 0;
}
