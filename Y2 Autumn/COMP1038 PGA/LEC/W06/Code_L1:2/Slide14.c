//-------------------------------- example 4 ----------------------------------
#include <stdio.h>

int main()
{
	// different functions for output
	printf("%s", "Hello World!\n");
	puts("Hello World!");           // puts会帮你自动换行
	
	char arr[15] = {'\0'};
	sprintf(arr, "Hello World!\n"); // "Hello World"会被自动存进arr数组
	printf("%s", arr);
	
	// different functions for input
	printf("\nGetting two integer inputs:\n");
	scanf("%[^\n]", arr);           // get every character excluding \n
	printf("arr contains %s\n\n", arr);
	
	int a = 0;
	int b = 0;
	printf("Getting two integer inputs from arr:\n");
	sscanf(arr, "%d %d", &a, &b);   // read the input from the string
	printf("arr contains %s, a = %d, b = %d\n", arr, a, b);
	

	while ( getchar() != '\n' );
	// consume the left over \n from scanf in line 101
	
	printf("\n\nEnter a sentence longer than 15 characters: ");
	fgets(arr, 15, stdin);			// stdin means "standard input"
	printf("%s\n", arr);			// which is the keyboard
	
	printf("\n\n");
	putchar('a');
	
	return 0;
}