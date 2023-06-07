//-------------------------------- example 5 ----------------------------------
#include <stdio.h>

int main(void)
{
	int a = 4;

	if(!a) // better to use explicit comparison i.e. a == 0
	{
		printf("a is equal to false\n");
	}
	else
	{
		printf("a is equal to true\n");
	}
	
	if(a) // better to use explicit comparison i.e. a != 0
	{
		printf("a is equal to true\n");
	}
	else
	{
		printf("a is equal to false\n");
	}
	
	if(a == 0)
	{
		printf("a is equal to false\n");
	}
	else
	{
		printf("a is equal to true\n");
	}
	
	if(a != 0)
	{
		printf("a is equal to true\n");
	}
	else
	{
		printf("a is equal to false\n");
	}
	
	
	return 0;
}