//-------------------------------- example 7 ----------------------------------
#include <stdio.h>

int main(void)		// slide 3
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
	
	printf("\n\nThe marks entered:\n");
	for(m = 0; m < NUM_MOD; m++)
	{
		for(s = 0; s < NUM_STUDENTS; s++)
		{
			printf("Student %d, module %d: %d\n", s+1, m+1, marks[m][s]);
		}
	}
	
	return 0;
}