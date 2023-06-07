//-------------------------------- example 12 ----------------------------------
#include <stdio.h>

int main(void)	// Bubble Sort
{
	// 输入部分
	int count = 0;
	printf("Please enter number of input: ");
	scanf("%d", &count);
	
	int myInt[count];
	int i = 0;
	for(i = 0; i < count; i++)
	{
		printf("Please enter an input: ");
		scanf("%d", &myInt[i]);
	}
	
	// 输出无序数列
	printf("You have entered:\n");
	for(i = 0; i < count; i++)
	{
		
		printf("%d ", myInt[i]);
	}
	printf("\n");
	
	// Bubble Sort
	int temp = 0;
	int j = 0;
	for(i = 0; i < count; i++)
	{
		for(j = 0; j < (count - 1); j++)
		{
			if(myInt[j] < myInt[(j + 1)])	// Bubbling
			{
				temp = myInt[j];
				myInt[j] = myInt[(j + 1)];
				myInt[(j + 1)] = temp;
			}
		}
	}
	
	// 输出有序数列
	printf("Sorted array:\n");
	for(i = 0; i < count; i++)
	{
		
		printf("%d ", myInt[i]);
	}
	printf("\n");
	
	return 0;
}