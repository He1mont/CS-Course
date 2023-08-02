//-------------------------------- example 8 ----------------------------------
// this example is similar to example 7 but with no side effect order
#include <stdio.h>

int main(void)
{
	int a = 10;
	int b = 20;
	int c = 0;
	
	//c = (a >= 10) && (++b >= 15); // this is the same as example 7
	// NOTE: an example with side effect order, do not write like this
	
	++b;
	c = (a >= 10) && (b >= 15);
	printf("a = %d, b = %d, and c = %d\n", a, b, c);
	// NOTE: if your intention is to always increment b then take
	//       that out of the assignment to avoid "side effect order"
	
	a = 10;
	b = 20;
	c = 0;
	
	//c = (a > 10) && (++b >= 15); // this is the same as example 7
	// NOTE: an example with side effect order, do not write like this
	
	++b;
	c = (a > 10) && (b >= 15);
	printf("a = %d, b = %d, and c = %d\n", a, b, c);
	// NOTE: if your intention is to always increment b then take
	//       that out of the assignment to avoid "side effect order"
	
	return 0;
}