//-------------------------------- example 13 ----------------------------------
#include <stdio.h>

int main(void)
{	
	int n = 4;
	int s[4] = {-1, 0, 1, 2};
	int i = 0;
	
	if(n > 0)
		for(i = 0; i < n; i++)
			if(s[i] > 0)
				printf("non zero positive\n");
	else
		printf("no data\n");
	
	// NOTE: else statement here is matched to the nearest if, which
	//       in this example isn't what you want
		
	
	return 0;
}