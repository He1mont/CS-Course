#include <stdio.h>
#include <string.h>

void main( ) 
{ struct employee 
  { char name[25]; 
    int age; 
    float bs; 
  }; 
  struct employee e; 
  strcpy (e.name, "Hacker"); 
  age = 25; 
  printf ("\n%s %d", e.name, age);
}
