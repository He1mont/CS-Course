//-------------------------------- example 12 ----------------------------------
#include <stdio.h>

int total = 10; 
// avoid using global variables, this is for example purpose only

void myFunction(void);

int main(void)
{	
	printf("%d\n", total);
	
	myFunction();
	
	printf("%d\n", total);
	
	return 0;
}

void myFunction(void)
{
	int total = 20; // with and without int 
	printf("%d\n", total);
}