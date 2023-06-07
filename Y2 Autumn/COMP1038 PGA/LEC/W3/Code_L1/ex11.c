//-------------------------------- example 11 ----------------------------------
#include <stdio.h>

int main(void)	// 字符串的4种输出形式
{
	char str[] = "This is Text";
	
	printf("%s\n", str);
	
	printf("%s\n", (str + 5));
	// NOTE: this is the use of pointer arithmetic, don't worry we will
	//       look at this in more details when we start learning about 
	//       pointer
	
	printf("%s\n", &str[5]);
	// NOTE: this is print from memory address of the 6th element 
	//       in str array
	
	puts(str);
	
	return 0;
}