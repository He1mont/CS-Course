#include <stdio.h>

int main(void)	// 数组的地址
{	
	char a[10] = {'\0'}; 
	int b[10] = {0};
	
    // 输出数组的地址
    
	printf("%p\n", a);
	printf("%p\n", b);
	
	// NOTE: the address of a and b is the same as a[0] and b[0]
	
	// 输出数组a和b每个变量的地址
	int i = 0;
	printf("\n\nPrint memory addresses of a:\n");
	for(i = 0; i < 10; i++)
	{
		printf("%p\n", &a[i]);
	}
	printf("\n\n");
	printf("Print memory addresses of b:\n");
	for(i = 0; i < 10; i++)
	{
		printf("%p\n", &b[i]);
	}
	
	// initialise arrays with a, or b 
	for(i = 0; i < 10; i++)
	{
		a[i] = 'a';
		b[i] = 98; // decimal ascii value of b
	}
	
	// 输出字符
	printf("\n\nPrint as character\n");
	for(i = 0; i < 10; i++)
	{
		printf("%c ", a[i]);
	}
	printf("\n");
	for(i = 0; i < 10; i++)
	{
		printf("%c ", b[i]);
	}
	printf("\n");
	
	// 输出ASCII值
	printf("\n\nPrint as integer\n");
	for(i = 0; i < 10; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
	for(i = 0; i < 10; i++)
	{
		printf("%d ", b[i]);
	}
	printf("\n");

	return 0;
}