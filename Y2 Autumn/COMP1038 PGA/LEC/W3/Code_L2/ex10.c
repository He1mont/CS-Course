//-------------------------------- example 10 ----------------------------------
// this example is similar to example 9 but with no side effect order
#include <stdio.h>

int main(void)
{
	int a = 1;
	int b = 2;
	int c = 0;
	
	//c = (a >= 1) || (++b >= 3); // this is the same as example 9
	// NOTE: an example with side effect order, do not write like this
	
	++b;
	c = (a >= 1) || (b >= 3);
	printf("a = %d, b = %d, and c = %d\n", a, b, c);	
	// NOTE: if your intention is to always increment b then take
	//       that out of the assignment to avoid "side effect order"
	
	a = 1;
	b = 2;
	c = 0;
	
	//c = (a > 1) || (++b >= 3); // this is the same as example 9
	// NOTE: an example with side effect order, do not write like this
	
	++b;
	c = (a > 1) || (b >= 3);
	printf("a = %d, b = %d, and c = %d\n", a, b, c);
	// NOTE: if your intention is to always increment b then take
	//       that out of the assignment to avoid "side effect order"
	
	return 0;
}