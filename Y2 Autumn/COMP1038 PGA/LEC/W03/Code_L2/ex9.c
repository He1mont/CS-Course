//-------------------------------- example 9 ----------------------------------
#include <stdio.h>

int main(void)
{
	int a = 1;
	int b = 2;
	int c = 0;
	
	c = (a >= 1) || (++b >= 3);
	printf("a = %d, b = %d, and c = %d\n", a, b, c);	
	// NOTE: how second clause is not executed in this assignment 
	//       of c because the first clause is true, therefore the 
	//       value of b is unchanged
	
	a = 1;
	b = 2;
	c = 0;
	
	c = (a > 1) || (++b >= 3);
	printf("a = %d, b = %d, and c = %d\n", a, b, c);
	
	// NOTE: do not write statements like this, this is a bad example
	
	return 0;
}