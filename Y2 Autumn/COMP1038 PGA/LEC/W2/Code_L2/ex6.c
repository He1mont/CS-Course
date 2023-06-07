//-------------------------------- example 6 ----------------------------------
#include <stdio.h>

int main(void)
{
	printf("Roses are red");
	printf("Violet are blue");
	printf("Sugar is sweet");
	printf("And so are you!");	
	// DIY: add \n at the end of the sentences before the second "
	//      compile, run the program, and compare the output 
	//      with and without \n
	
	printf("\n\n%c", 'A');
	printf("\t%d", 'A');
	// NOTE: the output of when different format specifiers are used
	//       on the same input i.e. 'A'
	
	printf("\n%10c", 'A');
	printf("\t%d", 'A');
	
	printf("\n\n%d", 1.23456789);
	// NOTE: what happen when you display floating number using %d
	printf("\t%f", 1.23456789);
	printf("\t%.2f", 1.23456789);
	printf("\t%.4f", 1.23456789);
	
	short myshort = 32768;
	printf("\n%d", myshort);
	// DIY: change 32768 to 32769, compile, run the program 
	//      and compare the output
	

    
	printf("\n%%");
	// NOTE: the number of '%' shown on the output
	
	return 0;
}