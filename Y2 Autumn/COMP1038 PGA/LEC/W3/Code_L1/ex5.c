//-------------------------------- example 5 ----------------------------------
#include <stdio.h>

int main(void)	// 在W3 Note Section3-9 上有调试过程
{
	char myChar = 'a';
	char myString[10] = "Hi There!";
	
	printf("%c\n", myChar);
	printf("%s\n", myString);
	
    // input 1
	printf("Please enter a word: ");
	scanf("%c", myString);
	printf("You have entered %s\n", myString);
	
    // input 2
	printf("Please enter a word: ");
	scanf("%s", myString);
	printf("You have entered %s\n", myString);

	
	return 0;
}