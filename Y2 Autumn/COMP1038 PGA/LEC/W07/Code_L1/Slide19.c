// pass individual Structure elements or the entire structure

#include <stdio.h>

struct book{
    char name[25];
    char author[25];
    int callno;
};

void display1(char*, char*, int);
void display2 (struct book b);

int main(void)
{
    struct book b1 = {"C How to program", "Paul Deitel", 101};

    display1(b1.name, b1.author, b1.callno); // passing structure member
    display2(b1);                            // passing the entire structure
    return 0;
}

void display1 (char *s, char *t, int n)      // Called function
{
    printf("%s %s %d\n\n", s, t, n);
}

void display2 (struct book b)
{
    printf("%s, %s, %d\n\n", b.name, b.author, b.callno);
}