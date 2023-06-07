//-------------------------------- example 9 ----------------------------------
#include <stdio.h>

int main(void)  // while();
{
   int counter = 0;
	int input = 0;
	int sum = 0;
	int limit = 0;
	
	printf("Please enter the number of input: ");
	scanf("%d", &limit);
	
	while(counter < limit);     // 注意分号
	{
		// DIY: run the program once and note that the program will never
		//      go pass line 215.
		//      Now press ctrl c (Windows user) or press ctrl z (Linux),
		//      delete the ';' after '(counter < limit)', compile,
		//      run the program again and compare the output
		printf("Please enter an input: ");
		scanf("%d", &input);
		
		sum = sum + input;
		counter = counter + 1;
	}
	
	printf("The sum of the input numbers is %d\n", sum);
	
	return 0;
}