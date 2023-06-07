#include <stdio.h>

union Test
{
  int x;
  char c;
};

void main()
{
  union Test t = {1};
  
  printf("%d, %c", t.x, t.c);
}


