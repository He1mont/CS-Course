//-------------------------------- example 3 ----------------------------------
#include <stdio.h>

int main(void)
{
	int a = 4;
	int b = 0;
	
	b = a++;
	printf("%d, %d\n", a, b);
	
	a = 4;
	b = 0;
	
	b = ++a;
	printf("%d, %d\n", a, b);
	// NOTE: the difference between a++ and ++a in the value of b
	
	a = 1, b = 2;
	int c = 3, d = 0;
	
	d = (++a) - (b--) + (--c);
	
	printf("%d, %d, %d, %d\n", a, b, c, d);
	
	a = 1, b = 2;
	c = 3, d = 0;
	
	d = (a++) - (--b) + (c--);
	
	printf("%d, %d, %d, %d\n", a, b, c, d);
	// NOTE: the difference between var++ and ++var (or var-- and --var) 
	//       in the value of d
	
	return 0;
}