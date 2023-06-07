//-------------------------------- example 7 ----------------------------------
#include <stdio.h>

int main(void)	// slide 24 字符串初始化各种定义
{
	//char myString[8]; // no initialisation
	
	//char myString[8] = "message";
	
	//char myString[] = "message";
	
	//char myString[] = {'m', 'e', 's', 's', 'a', 'g', 'e', '\0'};
	
	// DIY: uncomment the above 4 declarations one at a time, compile,
	//      run, and compare the output
	
	int i = 0;
	for(i = 0; i < 8; i++)
	{
		if(myString[i] == '\0') 
		{
			printf("*");
		}
		else
		{
			printf("%c", myString[i]);
		}
	}
	
	return 0;
}