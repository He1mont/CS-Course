//-------------------------------- example 9 ----------------------------------
#include <stdio.h>

#define DAYS 7

int printDay(int index);

int main(void)				// 计算一周的存款总数和平均值
{
	int saving[DAYS] = {0};	// 用来储存每日的存款
	int total = 0;
	int nChar = 0;
	
	int i = 0;
	int j = 0;
	for(i = 0; i < DAYS; i++)
	{
		printf("Enter the saving amount for ");
		nChar = printDay(i);	// nChar
		printf(":");
		for(j = 0; j < (10 - nChar); j++)
		{
			printf(" ");		// 输出时对齐
		}
		
		scanf("%d", &saving[i]);
		total = total + saving[i];
	}
	printf("\n\n");
	
	for(i = 0; i < DAYS; i++)
	{
		nChar = printDay(i);
		printf(" has a saving of: %d\n", saving[i]);
	}
	
	printf("--------------------------------\n");
	
	printf("Total is %d\n", total);
	printf("Average is %d\n", total / DAYS);
	
	return 0;
}

int printDay(int index)	// 返回字符的个数
{
	int count = 0;
	switch(index)
	{
		case 0:
			printf("Monday");
			count = 6;
			break;
		case 1:
			printf("Tuesday");
			count = 7;
			break;
		case 2:
			printf("Wednesday");
			count = 9;
			break;
		case 3:
			printf("Thursday");
			count = 8;
			break;
		case 4:
			printf("Friday");
			count = 6;
			break;
		case 5:
			printf("Saturday");
			count = 8;
			break;
		case 6:
			printf("Sunday");
			count = 6;
			break;
	}
	return count;
}