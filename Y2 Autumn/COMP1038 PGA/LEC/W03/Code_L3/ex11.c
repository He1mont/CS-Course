//-------------------------------- example 11 ----------------------------------
#include <stdio.h>

int main(void)	// Selection Sort
{
	int count = 0;
	printf("Please enter number of input: ");
	scanf("%d", &count);
	
	// 输入部分
	int myInt[count];
	int i = 0;
	for(i = 0; i < count; i++)
	{
		printf("Please enter an input: ");
		scanf("%d", &myInt[i]);
	}
	
	// 输出未排序数列
	printf("You have entered:\n");
	for(i = 0; i < count; i++)
	{
		printf("%d ", myInt[i]);
	}
	printf("\n");
	
	// Selection Sort
	int min = 0;
	int index = -1;
	int temp = 0;
	int j = 0;
	
	for(i = 0; i < count; i++)
	{
		index = i;
		min = myInt[i];
		for(j = i+1; j < count; j++)
		{
			if(min < myInt[j])
			{
				min = myInt[j];
				index = j;
				// find the location of the smallest unsorted number
			}
		}
		
		if(index != i)
		{
			temp = myInt[i];
			myInt[i] = myInt[index];
			myInt[index] = temp;
			// swap the smallest unsorted number
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