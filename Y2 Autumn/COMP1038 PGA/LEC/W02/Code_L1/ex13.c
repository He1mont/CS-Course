//-------------------------------- example 13 ----------------------------------
#include <stdio.h>

int main(void)
{
	int arr[2];
	arr[0] = 0;
	arr[1] = 1;
	
	int i = 0;
	for(i = 0; i < 10; i++)
	{	
		// DIY: try change '3' to 10, compile, run the program
		//      and compare the output
		printf("%d\n", arr[i]);
	}
	
	return 0;
}