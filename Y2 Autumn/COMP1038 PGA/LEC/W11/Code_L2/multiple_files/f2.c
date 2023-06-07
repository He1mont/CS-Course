#include<stdio.h>
#include "f.h"

extern int a;
int b = 20;

void f2test()
{
   f1test();
   b = a+b;
   printf("In f2.test %d\n", b);
}

void main()
{
   printf("In f2.main\n");
   f2test();
}
