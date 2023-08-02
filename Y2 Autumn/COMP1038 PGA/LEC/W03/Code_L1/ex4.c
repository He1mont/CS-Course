//-------------------------------- example 4 ----------------------------------
#include <stdio.h>

int main(void)	// slide 19 用二维数组计算一周喝的水
{
	int water[7][24] = {0};
	
	int time = 0;
	int day = 0;
	int sum = 0;
	
	do
	{
		printf("Please enter the day and time you have some water: ");
		scanf("%d%d", &day, &time);
		
		if((time < 0) || (time >= 24) || (day < 0) || (day >= 7))
		{
			break;
		}
		
		printf("Please enter the amount of water: ");
		scanf("%d", &water[day][time]);
		sum = sum + water[day][time];
		
	}while((time >= 0) && (time < 24) && (day >= 0) && (day < 7));
	
	printf("\n\nThe amount of water you drank:\n");
	int i = 0, j = 0;
	for(i = 0; i < 7; i++)
	{
		for(j = 0; j < 24; j++)
		{
			printf("%d ", water[i][j]);
		}
		printf("\n");
	}
	printf("Total number of glasses: %d\n", sum);
	
	for(i = 0; i < 7; i++)
	{
		printf("%p\n", water[i]);
	}
	
	return 0;
}
