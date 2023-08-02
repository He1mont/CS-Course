//-------------------------------- example 1 ----------------------------------
/*#include <stdio.h>

int main(void)
{	
	char a[10] = {'\0'}; 
	int b[10] = {0};
	
	printf("%p\n", a);
	printf("%p\n", b);
	
	// NOTE: the address of a and b is the same as a[0] and b[0]
	
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
}*/


//-------------------------------- example 2 ----------------------------------
/*#include <stdio.h>

#define SIZE 10

int main(void)
{		
	int size = 10;
	//int array[size] = {0};
	// DIY: uncomment the above line and note the error.
	//      Because size obtains the value 10 at run time, therefore cannot
	//      be used to declare array that use short cut initialisation
	
	//int array[SIZE] = {0};
	// DIY: uncomment the above line and note that there is no error
	//      Because SIZE obtains the value 10 at compile time
	// NOTE: size and SIZE is not the same thing!!
	
	//int array[size];
	// DIY: uncomment the above line and note that there is no error
	//      Because size obtains the value 10 at run time, but this example
	//      use no shortcut initialisation
	
	//int array[10] = {0};
	// DIY: uncomment the above line and note that there is no error
	//      Because the value 10 is used directly, shortcut initialisation
    //      is not a problem

	//int array[size]; // or use int array[10];
	//int i = 0;
	//for(i = 0; i < size; i++)
	//{
	//	array[i] = 0;
	//}	
	// DIY: uncomment the above 6 lines, note that there is no error, 
	//      but compare to line 81, this example also initialise all elements
	//      to zero
		
	return 0;
}*/


//-------------------------------- example 3 ----------------------------------
/*#include <stdio.h>

int main(void)
{	
	char a[10] = {'\0'};  // initialise all elements to '\0' null char
	char b[10] = {'\0'}; 
	char c[10] = {'\0'};
	
	int i = 0;
	
	printf("a: %p\n", a); // FF22 = 65314 i.e. hexadecimal = decimal
	printf("b: %p\n", b); // FF18 = 65304
	printf("c: %p\n", c); // FF0E = 65294
	// NOTE: memory locations and sizes of variables vary from 
	//       machine to machine
	
	// initialise arrays with a, b or c	
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
}*/


//-------------------------------- example 4 ----------------------------------
/*#include <stdio.h>

int main(void)
{
	int water[7][24] = {0};
	
	int time = 0;
	int day = 0;
	int sum = 0;
	
	do
	{
		printf("Please enter the day and time you have some water: ");
		scanf("%d%d", &day, &time);
		
		if((time < 0) || (time >= 24) || (day < 0) || (day >= 7))
		{
			break;
		}
		
		printf("Please enter the amount of water: ");
		scanf("%d", &water[day][time]);
		sum = sum + water[day][time];
		
	}while((time >= 0) && (time < 24) && (day >= 0) && (day < 7));
	
	printf("\n\nThe amount of water you drank:\n");
	int i = 0, j = 0;
	for(i = 0; i < 7; i++)
	{
		for(j = 0; j < 24; j++)
		{
			printf("%d ", water[i][j]);
		}
		printf("\n");
	}
	printf("Total number of glasses: %d\n", sum);
	
	for(i = 0; i < 7; i++)
	{
		printf("%p\n", water[i]);
	}
	
	return 0;
}*/


//-------------------------------- example 5 ----------------------------------
/*#include <stdio.h>

int main(void)
{
	char myChar = 'a';
	char myString[10] = "Hi There!";
	
	printf("%c\n", myChar);
	printf("%s\n", myString);
	
	printf("Please enter a word: ");
	scanf("%c", myString);
	// DIY: enter at least two words in the user input prompt
	//      e.g. hello audience
	// NOTE: this scanf takes 1 character
	
	printf("You have entered %s\n", myString);
	// NOTE: in the output the first character of your input 
	//       replaced "H" in "Hi There"
	//       e.g. "h" from "hello audience" now replaced "H" in "Hi There"
	
	printf("Please enter a word: ");
	scanf("%s", myString);
	// NOTE: you didn't have the opportunity to enter any input here
	
	printf("You have entered %s\n", myString);
	// NOTE: the rest of the characters in your first word appears here
	//       the output shows "ello"
	
	// NOTE: this is because scanf %s stop reading at white space
	
	return 0;
}*/


//-------------------------------- example 6 ----------------------------------
/*#include <stdio.h>

int main(void)
{
	char myString3[10] = "!\0!\0!\0!\0!";
	char myString2[10] = "Hey There\0";
	char myString[10] = "!!!!!!!!!\0";
	
	
	printf("str3: %s\n", myString3);
	// NOTE: printf stops when it founds '\0' null character
	//       if you don't have null characters it will continue to print
	//       the content of your memory until it finds one or crash the 
	//       program
	printf("str2: %s\n", myString2);
	printf("str1: %s\n", myString);
	
	printf("Please enter a word: ");
	scanf("%[^\n]", myString);
	// DIY: enter two words which has more than 10 characters in total
	//      e.g. hello audience here
	
	printf("str3: %s\n", myString3);
	printf("str2: %s\n", myString2);
	printf("str1: %s\n", myString);
	// NOTE: str1 printf %s print content of myString and myString2 
	//       when the above line i.e. 287 is called
	
	printf("\n\n... using printf %%c to print out str2\n");
	// NOTE: needs to use %% to display % on the screen
	for(int i = 0; i < 10; i++)
	{
		printf("%c", myString2[i]);
	}
	printf("\n\n");
	// NOTE: the output using printf %c compare to printf using %s 
	//       of myString2 above i.e. line 286
	
	printf("\n\n... using printf %%c to print out str2\n");
	// NOTE: needs to use %% to display % on the screen
	for(int i = 0; i < 10; i++)
	{
		printf("%c", myString3[i]);
	}
	printf("\n\n");
	// NOTE: the output using printf %c compare to printf using %s 
	//       of myString3 above i.e. line 285
	
	printf("str1: %p\n", myString);
	printf("str2: %p\n", myString2);
	printf("str3: %p\n", myString3);
	
	// NOTE: your output may be different from the slides if the memory
	//       space for these three arrays are not arranged in the same 
	//       way	
	
	return 0;
}*/


//-------------------------------- example 7 ----------------------------------
/*#include <stdio.h>

int main(void)
{
	//char myString[8]; // no initialisation
	
	//char myString[8] = "message";
	
	//char myString[] = "message";
	
	//char myString[] = {'m', 'e', 's', 's', 'a', 'g', 'e', '\0'};
	
	// DIY: uncomment the above 4 declarations one at a time, compile,
	//      run, and compare the output
	
	int i = 0;
	for(i = 0; i < 8; i++)
	{
		if(myString[i] == '\0') 
		{
			printf("*");
		}
		else
		{
			printf("%c", myString[i]);
		}
	}
	
	return 0;
}*/


//-------------------------------- example 8 ----------------------------------
/*#include <stdio.h>

int main(void)
{
	char myString[10] = {'\0'};
	
	printf("Please enter a word: ");
	scanf("%[^\n]", myString);
	// DIY: enter two words e.g. hello audience
	
	while(getchar() != '\n');

	printf("%s\n", myString);
	
	printf("Please enter a word: ");
	scanf("%[abc ]", myString);
	// NOTE: this line is skipped because the input buffer is not empty
	
	// DIY: now uncomment getchar() line, compile, run and compare 
	//      the output
	//      This time you will see that you get the change to enter the
	//      second input
	
	// DIY: now enter a word that begins with a, b, c or a space
	//      run again and compare the output 
	
	printf("%s\n", myString);
	
	return 0;
}*/


//-------------------------------- example 9 ----------------------------------
/*#include <stdio.h>

#define DAYS 7

int printDay(int index);

int main(void)
{
	int saving[DAYS] = {0}; 
	int total = 0;
	int nChar = 0;
	
	int i = 0;
	int j = 0;
	for(i = 0; i < DAYS; i++)
	{
		printf("Enter the saving amount for ");
		nChar = printDay(i);
		printf(":");
		for(j = 0; j < (10 - nChar); j++)
		{
			printf(" ");
		}
		
		scanf("%d", &saving[i]);
		total = total + saving[i];
	}
	printf("\n\n");
	
	for(i = 0; i < DAYS; i++)
	{
		nChar = printDay(i);
		//printf(" has a saving of: %*d\n", (10 - nChar) , saving[i]);
		printf(" has a saving of: %d\n", saving[i]);
		
		// DIY: uncomment the above printf i.e. line 419 and comment
		//      the following printf i.e. line 420, compile, run, and
		//      compare the output
	}
	
	printf("--------------------------------\n");
	
	printf("Total is %d\n", total);
	printf("Average is %d\n", total / DAYS);
	
	return 0;
}

int printDay(int index)
{
	int count = 0;
	switch(index)
	{
		case 0:
			printf("Monday");
			count = 6;
			break;
		case 1:
			printf("Tuesday");
			count = 7;
			break;
		case 2:
			printf("Wednesday");
			count = 9;
			break;
		case 3:
			printf("Thursday");
			count = 8;
			break;
		case 4:
			printf("Friday");
			count = 6;
			break;
		case 5:
			printf("Saturday");
			count = 8;
			break;
		case 6:
			printf("Sunday");
			count = 6;
			break;
	}
	return count;
}*/


//-------------------------------- example 10 ----------------------------------
/*#include <stdio.h>
#include <string.h>

#define DAYS 7

int printDay(int index);

int main(void)
{
	int saving[DAYS] = {0}; 
	int total = 0;
	int nChar = 0;
	
	int i = 0;
	int j = 0;
	for(i = 0; i < DAYS; i++)
	{
		printf("Enter the saving amount for ");
		nChar = printDay(i);
		printf(":");
		for(j = 0; j < (10 - nChar); j++)
		{
			printf(" ");
		}
		
		scanf("%d", &saving[i]);
		total = total + saving[i];
	}
	printf("\n\n");
	
	for(i = 0; i < DAYS; i++)
	{
		nChar = printDay(i);
		printf(" has a saving of: %*d\n", (10 - nChar), saving[i]);
	}
	
	printf("--------------------------------\n");
	
	printf("Total is %d\n", total);
	printf("Average is %d\n", total / DAYS);
	
	return 0;
}

int printDay(int index)
{
	int count = 0;
	char day[7][10] = {"Monday", "Tuesday", "Wednesday", "Thursday", 
					"Friday", "Saturday", "Sunday"};
					
	printf("%s", day[index]);
	
	return strlen(day[index]);
	
	// NOTE: example 9 and 10 are almost exactly the same accept in the 
    //       printDay function
}*/


//-------------------------------- example 11 ----------------------------------
/*#include <stdio.h>

int main(void)
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
}*/


//-------------------------------- example 12 ----------------------------------
/*#include <stdio.h>

int main(void)
{
	char str[10]; // no initialisation
	str[0] = 'a';
	
	printf("%s\n", str);
	
	//int i = 0;
	//for(i = 0; i < 10; i++)
	//{
	//	if(str[i] == '\0')
	//	{
	//		printf("*");
	//	}
	//	else
	//	{
	//		printf("%c ", str[i]);
	//	}
	//}
	//printf("\n");
	
	// NOTE: your output of this printf may or may not have more than 'a'
	
	// DIY: uncomment the for loop to see the content of your array
	
	char str2[10] = {0}; 
	str2[0] = 'a';
	
	printf("%s\n", str2);
	
	//for(i = 0; i < 10; i++)
	//{
	//	if(str2[i] == '\0')
	//	{
	//		printf("*");
	//	}
	//	else
	//	{
	//		printf("%c ", str2[i]);
	//	}
	//}
	//printf("\n");
	
	char str3[10]; // no initialisation
	str3[0] = 'a';
	str3[1] = '\0';
	
	printf("%s\n", str3);
	
	//for(i = 0; i < 10; i++)
	//{
	//	if(str3[i] == '\0')
	//	{
	//		printf("*");
	//	}
	//	else
	//	{
	//		printf("%c ", str3[i]);
	//	}
	//}
	//printf("\n");
	
	// DIY: uncomment the for loop to see the content of your array
	
	return 0;
}*/

//-------------------------------- example 13 ----------------------------------
// Also used in iteration.c Example 13

/*#include <stdio.h>

int main(void)
{
   int total = 0;

   const int NUM_MONTHS = 12;
   for(int i = 0; i < NUM_MONTHS; i++)
   {
      int x = 0;
      printf("Enter month %d: ", i + 1);
      scanf("%d", &x);
      total = total + x;
   }

   printf("Total is %d\n", total);
   printf("Average is %d\n", total / NUM_MONTHS);
   
   // DIY: try to draw a graph 
   
   return 0;
}*/

