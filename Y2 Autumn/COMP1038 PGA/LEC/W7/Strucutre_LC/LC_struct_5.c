#include <stdio.h>

struct book
 {
     char name[25];
     char author[25];
     int callno;
 };

void display(struct book);

void main( ) 
{ 
  struct book b1 = {"C How to program","Paul Deitel",101};

  display(b1);
}

void display (struct book b)
{
     printf ("\n%s %s %d", b.name, b.author, b.callno );
} 



