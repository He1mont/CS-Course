//-------------------------------- example 14 ----------------------------------
// same as example 13, but braces are added to ensure correctness
#include <stdio.h>

int main(void)
{	
	int n = 4;
	int s[4] = {-1, 0, 1, 2};
	int i = 0;
	
	if(n > 0)
	{
		for(i = 0; i < n; i++)
		{
			if(s[i] > 0)
			{
				printf("non zero positive\n");
			}
		}
	}
	else
	{
		printf("no data\n");
	}
	
	// NOTE: a correctly braced program produce the correct result
		
	
	return 0;
}