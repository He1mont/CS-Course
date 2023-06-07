//-------------------------------- example 4 ----------------------------------
#include <stdio.h>

int main(void)
{
	int a = 4;
	int b = 5;
	int c = 5;
	int d = 6;
	
	printf("%d > %d = %d\n", a, b, a > b);
	printf("%d < %d = %d\n", a, b, a < b);
	
	printf("%d <= %d = %d\n", a, b, a <= b);
	printf("%d >= %d = %d\n", d, b, d >= b);
	printf("%d >= %d = %d\n", c, b, c >= b);
	printf("%d <= %d = %d\n", c, b, c <= b);
	
	printf("%d == %d = %d\n", c, b, c == b);
	printf("%d != %d = %d\n", c, b, c != b);
	
	return 0;
}