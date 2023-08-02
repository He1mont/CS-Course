//-------------------------------- example 8 ----------------------------------
#include <stdio.h>

int main(void)	// scanf("%[]", str)用来限制输入内容
{
	char myString[10] = {'\0'};
	
	printf("Please enter a word: ");
	scanf("%[^\n]", myString);
	// DIY: enter two words e.g. hello audience
	
	while(getchar() != '\n');

	printf("%s\n", myString);
	
	printf("Please enter a word: ");
	scanf("%[abc ]", myString);
	// NOTE: this line is skipped because the input buffer is not empty
	
	// DIY: now uncomment getchar() line, compile, run and compare 
	//      the output
	//      This time you will see that you get the change to enter the
	//      second input
	
	// DIY: now enter a word that begins with a, b, c or a space
	//      run again and compare the output 
	
	printf("%s\n", myString);
	
	return 0;
}