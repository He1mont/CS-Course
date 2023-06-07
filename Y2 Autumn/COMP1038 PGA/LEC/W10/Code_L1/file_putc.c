#include<stdio.h>

int main()
{
    FILE *fp;
    char ch;
    fp = fopen("./tmp/test.txt", "w");
    printf("Enter data...\n");

    while( (ch = getchar()) != EOF) {
        putc(ch, fp);
    }
    fclose(fp);
    return 0;
}
