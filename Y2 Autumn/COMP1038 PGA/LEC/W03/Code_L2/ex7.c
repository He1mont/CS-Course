//-------------------------------- example 7 ----------------------------------
#include <stdio.h>

int main(void)
{
	int a = 10;
	int b = 20;
	int c = 0;
	
	c = (a >= 10) && (++b >= 15);
	printf("a = %d, b = %d, and c = %d\n", a, b, c);
	
	a = 10;
	b = 20;
	c = 0;
	
	c = (a > 10) && (++b >= 15);
	printf("a = %d, b = %d, and c = %d\n", a, b, c);
	// NOTE: how second clause is not executed in the second assignment 
	//       of c because the first clause is false, therefore the 
	//       value of b is unchanged
	
	// NOTE: do not write statements like these, as they have "side effect
	//       order"
	
	return 0;
}