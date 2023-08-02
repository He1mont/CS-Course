// passing address of a structure variable

#include <stdio.h>

struct book{
    char name[25];
    char author[25];
    int callno;
};

void display(struct book *, int);
int input(struct book *);

int main(void)
{
    int n;
    struct book b1[20];
    n = input(b1);
    display (b1,n);

    return 0;
}

void display (struct book *b, int n)   // 这里b是一个指针
{
    int i;
    printf("\t\t Books Available: \n");
    printf("\t Sr. No \t Name \t Author \t Call No \n");

    for (i=0; i<n; i++){
        printf("\t %d \t\t %s \t %s \t %d\n", i+1, (b+i)->name, (b+i)->author, (b+i)->callno);
    }
}

