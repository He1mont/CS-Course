#include<stdio.h>

int main()
{
    FILE *fp;
    char ch;
    fp = fopen("./tmp/test.txt", "r");

    if(fp == NULL){
        printf("failed to open the file.");
    }

    while((ch = getc(fp))!= EOF){
        printf("%c",ch);
    }
    fclose(fp);
    
    return 0;
}
