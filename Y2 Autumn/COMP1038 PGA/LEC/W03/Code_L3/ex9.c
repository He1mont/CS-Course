//-------------------------------- example 9 ----------------------------------
#include <stdio.h>

int main(void)	// ex.8优化版
{
	const int NUM_MOD = 2;
	const int NUM_STUDENTS = 3;
	int marks[NUM_MOD][NUM_STUDENTS];
	
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
		for(s = 0; s < NUM_STUDENTS - 1; s++)
		{
			printf("%d, ", marks[m][s]);
		}
		
		printf("%d", marks[m][NUM_STUDENTS - 1]);
		printf("\n");
	}
	
	// NOTE: same as example 8 except the for loop is structured slightly
	//       differently
	
	return 0;
}