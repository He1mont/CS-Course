//-------------------------------- example 3 ----------------------------------
#include <stdio.h>
#include <stdlib.h> // strtod

// Instruction: try to use strtol and strtoul

int main()
{
	const char *str = "51.2% are admitted";
	const char *str2 = "41.5";
	const char *str3 = "My number is 1.23 not 4.56";
	char arr1[10] = "10.2";
	char arr2[10] = "10.2 today";
	
	char *sPtr;
	
	double d = 0.0;
	d = strtod(str, &sPtr);
	printf("double value is %f\tand the string is %s\n", d, sPtr);
	
	d = strtod(str2, &sPtr);
	printf("double value is %f\tand the string is %s\n", d, sPtr);
	
	d = strtod(str3, &sPtr);
	printf("double value is %f\tand the string is %s\n", d, sPtr);
	
	d = strtod(arr1, &sPtr);
	printf("double value is %f\tand the string is %s\n", d, sPtr);

	d = strtod(arr2, &sPtr);
	printf("double value is %f\tand the string is %s\n\n", d, sPtr);
	
	float f = 0.0;
	f = atof("51.2");
	printf("float value is %f\n", f);
	
	f = atof(str);
	printf("float value is %f\n", f);
	
	f = atof(str2);
	printf("float value is %f\n", f);
	
	f = atof(str3);
	printf("float value is %f\n", f);
	
	f = atof("1.23");
	printf("float value is %f\n", f);
	
	f = atof(arr1);
	printf("float value is %f\n", f);
	// NOTE: arr is array of characters
	
	return 0;
}