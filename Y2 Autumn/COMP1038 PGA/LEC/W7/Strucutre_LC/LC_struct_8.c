#include <stdio.h>

struct book 
{ char name[25]; 
char author[25];
int callno; 
}; 

void display(struct book *, int);
int input(struct book *); 

void main() 
{ int n; 
  struct book b1[20];
  n= input (b1);
  display (b1,n); 
}

void display(struct book *b , int n) 
{ 
  int i; 
  printf("\n\t\t Books Available "); 
  printf("\n\t Sr. No \t Name \t Author \t Call No \n"); 

  for(i=0;i<n;i++) 
  {  
    printf("\n\t %d \t\t %s \t %s \t %d",i+1, (b+i)->name, (b+i)->author, (b+i)->callno); 
  }
  printf("\n\n");
}

int input(struct book *b) 
{
  int i, n; 
  char c;
  printf("\n\t\t Enter No of books "); 
  scanf("%d",&n); 

  for(i=0;i<n;i++) 
  {  
    printf("\n\t Sr. No %d ", i+1); 
    printf("\n\t Name: ");
      
    while ((c=getchar()) != '\n' && c != EOF);
    gets((b+i)-> name);
    printf("\t Author Name: ");
    gets((b+i)-> author);
    printf("\t Call No: ");
    scanf("%d",&(b+i)->callno);
  }
  return n;
}


