//-------------------------------- example 13 ----------------------------------
#include <stdio.h>

int main(void)	// Linear Search
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
	
	// 输入需要找的数字
	int hunt = 0;
	printf("Please enter the desired number: ");
	scanf("%d", &hunt);
	
	// Linear Search
	int index = -1;
	for(i = 0; i < count; i++)
	{
		if(hunt == myInt[i])
		{
			index = i;
			break;
		}
	}
	
	if(index != -1)
	{
		printf("Number is found at index %d\n", index);
	}
	else
	{
		printf("Number is not found\n");
	}
	
	return 0;
}