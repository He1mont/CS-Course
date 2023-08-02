#include <stdio.h>

void main( ) 
{ 
  struct
  { char name[25]; 
    char language[10]; 
  }; 
  struct employee e = {"Hacker", "C"}; 
  printf ("\n%s %d", e.name, e.language); 
}
