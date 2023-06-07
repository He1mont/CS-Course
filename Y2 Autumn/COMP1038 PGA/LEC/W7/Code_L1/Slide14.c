#include <stdio.h>

int main(void)
{
    struct book{
        char name;
        float price;
        int pages;
    };

    struct  book b[3];  // Array of structure
    int i;
    char c;

    for (i=0; i<3; i++){
        printf("Enter name, price and pages: ");
        scanf("%c %f %d", &b[i].name, &b[i].price, &b[i].pages);

        while ((c=getchar()) != '\n' && c != EOF);  // EOF: End of File
        // 必须以换行结尾，并且把换行符给c
        // 如果没有这一行while，会跳过一次循环，原因是回车符被存进了b[i].name里
    }

    printf("%c %.1f %d\n\n", b[0].name, b[0].price, b[0].pages);
    printf("%c %.1f %d\n\n", b[1].name, b[1].price, b[1].pages);
    printf("%c %.1f %d\n\n", b[2].name, b[2].price, b[2].pages);


    return 0;
}