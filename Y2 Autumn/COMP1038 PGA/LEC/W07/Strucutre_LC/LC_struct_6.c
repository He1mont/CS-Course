#include <stdio.h>

void main ()
{
  struct book
  {
   char name[25];
   char author[25];
   int callno;
  };

  struct book b1 = {"C How to program","Paul Deitel",101}; 

  struct book *ptr; 

  ptr = &b1; 

  printf("\n%s %s %d", b1.name, b1.author, b1.callno);
  printf("\n%s %s %d", ptr->name, ptr->author, ptr->callno);
}


