//-------------------------------- example 4 ----------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)	// ex.2的进阶版
{
	const int NUM_MONTHS = 12;
	const int WIDTH = 70;
	
	// "Char *": Array of pointers
	const char *months[] = { "January", "February", "March",
			    "April", "May", "June", "July",
			    "August", "September", "October",
			    "November", "December"};
				
	int rainfall[NUM_MONTHS];
	int max_rain = 0;
	
	// Input the numbers and keep track of the maximum month value.
	int i = 0;
	for(i = 0; i < NUM_MONTHS; i++)
	{
		int x;
		printf("Enter %s: ", months[i]);
		scanf("%d", &x);
		
		if(x < 0)
		{
			printf("Invalid rainfall.\n");
			exit(1);
		}
		
		rainfall[i] = x;
		
		if(x > max_rain)
		{
			max_rain = x;
		}
	}
	
	printf("\n");

	// Print the graph lines month by month.
	for(i = 0; i < NUM_MONTHS; i++)
	{
		printf("%s", months[i]);
		
		// 保证输出时对齐
		int spaces = 10 - strlen(months[i]);
		int j = 0;
		for(j = 0; j < spaces; j++)
		{
			printf(" ");
		}
		
		// calculate and print the actual graph stars.
		float res = (rainfall[i] / (float)max_rain) * WIDTH;
		int num = (int)res;
		
		for(j = 0; j < num; j++)
		{
			printf("*");
		}
		// go to the next line ready for printing the next month.
		printf("\n");
	}
	
	return 0;
}