//-------------------------------- example 6 ----------------------------------
#include <stdio.h>

int main(void)	// slide 26 
{
    // 初始化三个字符串，printf在NULL时停止
	char myString3[10] = "!\0!\0!\0!\0!";
	char myString2[10] = "Hey There\0";
	char myString[10] = "!!!!!!!!!\0";
	
	printf("str3: %s\n", myString3);
	printf("str2: %s\n", myString2);
	printf("str1: %s\n", myString);
	
    printf("\n");

	printf("Please enter a word: ");
	scanf("%[^\n]", myString);
	// DIY: enter two words which has more than 10 characters in total
	//      e.g. hello audience here
	
	printf("str3: %s\n", myString3);
	printf("str2: %s\n", myString2);
	printf("str1: %s\n", myString);
	// NOTE: str1 printf %s print content of myString and myString2 
	//       when the above line i.e. 287 is called
	
    printf("\n");

	// 分别输出string2的各个character
	printf("... using printf %%c to print out str2: ");	// 在printf里表示%需要输入%%
	for(int i = 0; i < 10; i++)
	{
		printf("%c", myString2[i]);
	}

	printf("\n\n");

	// 分别输出string3的各个character
	printf("... using printf %%c to print out str3: "); 
	for(int i = 0; i < 10; i++)
	{
		printf("%c", myString3[i]);
	}
	
	// 在输出string3一整个字符串时，会停在第二个NULL字符
	// 但分别输出string3的各个character时，除了NULL字符都会显示出来

    printf("\n\n");

	// 输出地址
	printf("str1: %p\n", myString);
	printf("str2: %p\n", myString2);
	printf("str3: %p\n", myString3);
	
	// NOTE: your output may be different from the slides if the memory
	//       space for these three arrays are not arranged in the same 
	//       way	
	
	return 0;
}