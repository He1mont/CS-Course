#include <stdio.h> 
#include <string.h>


int main(void)	// 字符串的4种输出形式
{
	char str[] = "This is Text";
	
	printf("%s\n", str);
	
	printf("%s\n", (str + 5));

	printf("%s\n", &str[5]);
    
	puts(str);

    return 0; 

}