//-------------------------------- example 10 ----------------------------------
#include <stdio.h>
#include <string.h>

#define DAYS 7

int printDay(int index);	// 和ex.9有出入

int main(void)				// 和ex.9功能相同
{
	int saving[DAYS] = {0}; // 用来储存每日的存款
	int total = 0;
	int nChar = 0;
	
	int i = 0;
	int j = 0;
	for(i = 0; i < DAYS; i++)
	{
		printf("Enter the saving amount for ");
		nChar = printDay(i);
		printf(":");
		for(j = 0; j < (10 - nChar); j++)
		{
			printf(" ");	// 输出时对齐
		}
		
		scanf("%d", &saving[i]);
		total = total + saving[i];
	}
	printf("\n\n");
	
	for(i = 0; i < DAYS; i++)
	{
		nChar = printDay(i);
		printf(" has a saving of: %*d\n", (10 - nChar), saving[i]);
	}
	
	printf("--------------------------------\n");
	
	printf("Total is %d\n", total);
	printf("Average is %d\n", total / DAYS);
	
	return 0;
}

int printDay(int index)
{
	int count = 0;
	char day[7][10] = {"Monday", "Tuesday", "Wednesday", "Thursday", 
						"Friday", "Saturday", "Sunday"};
					
	printf("%s", day[index]);
	
	// day[0][10]来储存“Monday”
	// day[1][10]来储存“Tuesday”
	// 以此类推
	
	return strlen(day[index]);	// 用strlen函数获取字符串长度

}