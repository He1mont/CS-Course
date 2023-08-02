//-------------------------------- example 5 ----------------------------------
#include <stdio.h>
#include <string.h>

void rookie_mistake(char a[], char *p);

int main(void)
{
	char myString[10] = "Hello\0";
	char *myPointer = "Hello";	
	printf("%c, %p\n\n", *myPointer, myPointer);

	// NOTE: you can't change the content for string literal or
	//       even to move the pointer, but you can change the content 
	//       with array
	
	printf("size of myString \t%d\n", sizeof(myString));
	printf("strlen of myString \t%d\n", strlen(myString));
	// NOTE: '\0' is not included in the output
	
	printf("size of myPointer \t%d\n", sizeof(myPointer));
	printf("strlen of myPointer \t%d\n", strlen(myPointer));
	
	rookie_mistake(myString, myPointer);
	
	return 0;
}

void rookie_mistake(char a[], char *p)
{	
	printf("\n\nBelow is the content from rookie mistake!!\n");
	printf("size of myString \t%d\n", sizeof(a));
	// NOTE: read the warning message, the size here will be
	//       the size of pointer not array
	
	//printf("%strlen of myString \td\n", strlen(a));
	// DIY: uncomment this line, compile, and run the program
	//      you will see that your program will crash because you
	//      can't strlen a passed by referenced array 
	
	printf("size of myPointer \t%d\n", sizeof(p));
	printf("strlen of myPointer \t%d\n", strlen(p));
	
	// NOTE: as you can see here, you have to hard code the value 10
	//       for the size of myString, because sizeof(a) would be wrong
	int i = 0;
	for(i = 0; i < 10; i++)
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