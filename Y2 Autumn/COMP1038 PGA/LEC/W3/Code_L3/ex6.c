//-------------------------------- example 6 ----------------------------------
// similar to example 5, except that size of array is appropriately 
// passed to the function
#include <stdio.h>
#include <string.h>

void no_rookie_mistake(char a[], char *p, int a_size);

int main(void)
{
	char myString[10] = "Hello\0";
	char *myPointer = "Hello";
	// NOTE: you can't change the content for string literal or
	//       even to move the pointer, but you can change the content 
	//       with array
	
	printf("size of myString \t%d\n", sizeof(myString));
	printf("strlen of myString \t%d\n", strlen(myString));
	// NOTE: '\0' is not included in the output
	
	printf("size of myPointer \t%d\n", sizeof(myPointer));
	printf("strlen of myPointer \t%d\n", strlen(myPointer));
	
	no_rookie_mistake(myString, myPointer, 10);
	
	return 0;
}

void no_rookie_mistake(char a[], char *p, int a_size)
{	
	printf("\n\nBelow is the content from NO rookie mistake!!\n");
	printf("size of myString \t%d\n", a_size);
	
	printf("size of myPointer \t%d\n", sizeof(p));
	printf("strlen of myPointer \t%d\n", strlen(p));
	
	// NOTE: as you can see here, no need to hard code the value 10
	//       for the size of myString, because a_size contain the 
	//       correct value
	
	int i = 0;
	for(i = 0; i < a_size; i++)
	{
		if(a[i] != '\0')
		{
			printf("%c", a[i]);
		}
	}
	printf("\n");
	
	printf("%s\n", a);
	printf("%s\n", p);
	
}