//-------------------------------- example 3 ----------------------------------
#include <stdio.h>

int main(void)	// 数组的地址
{	
    // 初始化数组为NULL并且输出地址
	char a[10] = {'\0'};
	char b[10] = {'\0'}; 
	char c[10] = {'\0'};
	
	int i = 0;
	
	printf("a: %p\n", a); // FF22 = 65314 i.e. hexadecimal = decimal
	printf("b: %p\n", b); // FF18 = 65304
	printf("c: %p\n", c); // FF0E = 65294
	// NOTE: memory locations and sizes of variables vary from 
	//       machine to machine
	

	// 赋值后再输出
	for(i = 0; i < 10; i++)
	{
		a[i] = 'a';
		b[i] = 'b';
		c[i] = 'c';
	}
	
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
	for(i = 0; i < 10; i++)
	{
		printf("%c ", c[i]);
	}
	printf("\n");
	
	// assign 30 elements of c to be c!!!
	for(i = 0; i < 30; i++)
	{
		c[i] = 'c';
	}
	
	printf("\n\nAfter the reassignments\n");
	
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
	for(i = 0; i < 10; i++)
	{
		printf("%c ", c[i]);
	}
	printf("\n");
	
	// NOTE: This may not work exactly as shown on the slides on your
	//       own machine, compare the output of your line 117-119 with 
	//       the slides and see if there are exactly 10 memory spaces
	//       between each array
	
	return 0;
}


