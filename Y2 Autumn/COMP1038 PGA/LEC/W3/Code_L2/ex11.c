//-------------------------------- example 11 ----------------------------------
#include <stdio.h>

int main(void)
{
	int b = 0;
	b = 20, b = b + 30, printf("%d\n\n\n", b);
	// NOTE: comma is left associative
	
	int a = 0;
	for(a = 1, b = 2; b < 10; a++, b++)
	{
		printf("%d %d\n", a, b);
	}
	// NOTE: you have two initialisations and two updates in this for loop
	
	return 0;
}