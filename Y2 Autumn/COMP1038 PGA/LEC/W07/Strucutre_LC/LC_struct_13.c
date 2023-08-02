#include <stdio.h>

struct virus 
{ char signature[25]; 
  char status[20]; 
  int size; 
} v[2] = {"Yankee Doodle", "Deadly", 1813, "Dark Avenger", "Killer", 1795}; 

void main( ) 
{ int i; 
  for (i = 0 ; i <=1 ; i++) 
     printf ("\n%s %s", v.signature, v.status); 
}
