//-------------------------------- example 6 ----------------------------------
#include <stdio.h>

int main(void)
{
	int a = 4;
	int b = 2;
	
	a = (a + 6);
	printf("a = %d and b = %d\n", a, b);
	
	a = 4;
	b = 2;
	
	a += 6;
	printf("a = %d and b = %d\n", a, b);
	
	a = 4;
	b = 2;
	
	a = (a * (b + 3));
	printf("a = %d and b = %d\n", a, b);
	
	a = 4;
	b = 2;
	
	a *= (b + 3);
	printf("a = %d and b = %d\n", a, b);
	
	a = 4;
	b = 2;
	
	a = (a - (b + 8));
	printf("a = %d and b = %d\n", a, b);
	
	a = 4;
	b = 2;
	
	a -= (b + 8);
	printf("a = %d and b = %d\n", a, b);
	
	a = 4;
	b = 2;
	
	a = (a / b);
	printf("a = %d and b = %d\n", a, b);
	
	a = 4;
	b = 2;
	
	a /= b;
	printf("a = %d and b = %d\n", a, b);
	
	a = 4;
	b = 2;
	
	a = (a % (b + 1));
	printf("a = %d and b = %d\n", a, b);
	
	a = 4;
	b = 2;
	
	a %= (b + 1);
	printf("a = %d and b = %d\n", a, b);
	
	
	return 0;
}