//-------------------------------- example 2 ----------------------------------
#include <stdio.h>
#include <stdlib.h>

int main(void)  // 打印出每月的降雨量
{
	const int NUM_MONTHS = 12;
	const int WIDTH = 70;
	
	int rainfall[NUM_MONTHS];
	int max_rain = 0;
	
	// Input the numbers and keep track of the maximum month value.
	int i = 0;
	for(i = 0; i < NUM_MONTHS; i++)
	{
        // 输入每月降雨量
		int x;
		printf("Enter month %d: ", i + 1);
		scanf("%d", &x);
		
		if(x < 0)
		{
			printf("Invalid rainfall.\n");
			exit(1);    // 表示异常退出，只要不是0都表示异常退出
		}               // exit(0)表示正常退出
		
		rainfall[i] = x;
		
		if(x > max_rain)
		{
			max_rain = x;   // 标记最大的降雨量
		}
	}
	
    printf("\n");

	// Print the graph lines month by month.
	for(i = 0; i < NUM_MONTHS; i++)
	{
		printf("Month %d ", i+1);
		
        // 计算当月降雨量占最大降雨量的比重
        // 为了保证输出的图形不会太长也不会太短
		float res = (rainfall[i] / (float)max_rain) * WIDTH;
		
		int num = (int)res;
		int j = 0;
		for(j = 0; j < num; j++)
		{
			printf("*");
		}
		printf("\n");
	}
	
	return 0;
}