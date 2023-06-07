//-------------------------------- example 4 ----------------------------------
#include <stdio.h>

int main(void)
{
	unsigned char a = 250;
	int b = (int)a;
	int counter = 0;
	
	printf("a is %d and b is %d\n", a, b);
	
	while(counter < 10)
	{
		a = a + 1;
		counter = counter + 1;
		printf("%d + %d = %d\n", b, counter, a);
	}
	// NOTE: that 'a' doesn't go beyond 255
	
	
	a = 5;
	b = (int)a;
	counter = 0;
	
	printf("a is %d and b is %d\n", a, b);
	
	while(counter < 10)
	{
		a = a - 1;
		counter = counter + 1;
		printf("%d - %d = %d\n", b, counter, a);
	}
	// NOTE: that 'a' doesn't go below 0
		
		
	return 0;
}