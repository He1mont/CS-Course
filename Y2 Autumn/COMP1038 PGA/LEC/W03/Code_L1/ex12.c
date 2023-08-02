//-------------------------------- example 12 ----------------------------------
#include <stdio.h>

int main(void)		// 无初始化字符串的输出
{
	printf("This is String 1!\n");

	char str[10];	// no initialisation
	str[0] = 'a';
	
	printf("%s\n", str);	// 会输出乱码

	int i = 0;
	for(i = 0; i < 10; i++)
	{
		if(str[i] == '\0')
		{
			printf("*");
		}
		else
		{
			printf("%c ", str[i]);
		}
	}
	printf("\n\n");

	printf("This is String 2!\n");
	
	char str2[10] = {0}; 
	str2[0] = 'a';
	
	printf("%s\n", str2);
	
	for(i = 0; i < 10; i++)
	{
		if(str2[i] == '\0')
		{
			printf("*");
		}
		else
		{
			printf("%c ", str2[i]);
		}
	}
	printf("\n\n");

	printf("This is String 3!\n");
	
	char str3[10]; // no initialisation
	str3[0] = 'a';
	str3[1] = '\0';
	
	printf("%s\n", str3);
	
	for(i = 0; i < 10; i++)
	{
		if(str3[i] == '\0')
		{
			printf("*");
		}
		else
		{
			printf("%c ", str3[i]);
		}
	}
	printf("\n");
	
	return 0;
}