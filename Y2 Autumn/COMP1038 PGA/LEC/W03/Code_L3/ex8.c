//-------------------------------- example 8 ----------------------------------
#include <stdio.h>

int main(void)	// ex.7优化版
{
	const int NUM_MOD = 6;
	const int NUM_STUDENTS = 10;
	int marks[NUM_MOD][NUM_STUDENTS];
	// NOTE: might be a good idea to change to a smaller number if you
	//       too lazy to enter so many numbers
	
	int s = 0;
	int m = 0;
	for(s = 0; s < NUM_STUDENTS; s++)
	{
		for(m = 0; m < NUM_MOD; m++)
		{
			printf("Student %d, module %d: ", s+1, m+1);
			
			int mark = 0;
			scanf("%d", &mark);
			marks[m][s] = mark;
		}
	}
	
	for(m = 0; m < NUM_MOD; m++)
	{
		printf("Module %d: ", m+1);
		for(s = 0; s < NUM_STUDENTS; s++)
		{
			if(s == NUM_STUDENTS - 1)
			{
				printf("%d", marks[m][s]);		// 最后一位不需要逗号
			}
			else
			{
				printf("%d, ", marks[m][s]);	// 前面几位需要逗号
			}
		}
		printf("\n");
   }
   
   // NOTE: same as example 7 except the output is in a table format
   //       instead of a long list
   
   return 0;
}