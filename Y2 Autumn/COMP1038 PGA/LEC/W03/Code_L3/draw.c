//-------------------------------- example 1 ----------------------------------
// Also used in iteration.c

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
   
   return 0;
}*/


//-------------------------------- example 2 ----------------------------------
/*#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	const int NUM_MONTHS = 12;
	const int WIDTH = 70;
	
	int rainfall[NUM_MONTHS];
	int max_rain = 0;
	
	// Input the numbers and keep track of the maximum month value.
	int i = 0;
	for(i = 0; i < NUM_MONTHS; i++)
	{
		int x;
		printf("Enter month %d: ", i + 1);
		scanf("%d", &x);
		
		if(x < 0)
		{
			printf("Invalid rainfall.\n");
			exit(1);
		}
		
		rainfall[i] = x;
		
		if(x > max_rain)
		{
			max_rain = x;
		}
	}
	
	// Print the graph lines month by month.
	for(i = 0; i < NUM_MONTHS; i++)
	{
		printf("Month %d ", i+1);
		
		float res = (rainfall[i] / (float)max_rain) * WIDTH;
		
		int num = (int)res;
		int j = 0;
		for(j = 0; j < num; j++)
		{
			printf("*");
		}
		printf("\n");
	}
	
	return 0;
}*/


//-------------------------------- example 3 ----------------------------------
/*#include <stdio.h>

int main(void)
{
   float a = 0.0;
   float b = 0.0;
   float c = 2.34;
   
   b = (int)(c + 4.6);
   printf("%f, %f, %f\n", a, b, c);
   
   return 0;
}*/


//-------------------------------- example 4 ----------------------------------
/*#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	const int NUM_MONTHS = 12;
	const int WIDTH = 70;
	
	const char *months[] = { "January", "February", "March",
			    "April", "May", "June", "July",
			    "August", "September", "October",
			    "November", "December"};
				
	int rainfall[NUM_MONTHS];
	int max_rain = 0;
	
	// Input the numbers and keep track of the maximum month value.
	int i = 0;
	for(i = 0; i < NUM_MONTHS; i++)
	{
		int x;
		printf("Enter %s: ", months[i]);
		scanf("%d", &x);
		
		if(x < 0)
		{
			printf("Invalid rainfall.\n");
			exit(1);
		}
		
		rainfall[i] = x;
		
		if(x > max_rain)
		{
			max_rain = x;
		}
	}
	
	// Print the graph lines month by month.
	for(i = 0; i < NUM_MONTHS; i++)
	{
		// print month name.
		printf("%s", months[i]);
		
		// calculate and print extra padding to align with column 10.
		int spaces = 10 - strlen(months[i]);
		int j = 0;
		for(j = 0; j < spaces; j++)
		{
			printf(" ");
		}
		
		// calculate and print the actual graph stars.
		float res = (rainfall[i] / (float)max_rain) * WIDTH;
		int num = (int)res;
		
		for(j = 0; j < num; j++)
		{
			printf("*");
		}
		// go to the next line ready for printing the next month.
		printf("\n");
	}
	
	return 0;
}*/


//-------------------------------- example 5 ----------------------------------
/*#include <stdio.h>
#include <string.h>

void rookie_mistake(char a[], char *p);

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
	
}*/


//-------------------------------- example 6 ----------------------------------
// similar to example 5, except that size of array is appropriately 
// passed to the function
/*#include <stdio.h>
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
	
}*/


//-------------------------------- example 7 ----------------------------------
/*#include <stdio.h>

int main(void)
{
	const int NUM_MOD = 6;
	const int NUM_STUDENTS = 10;
	int marks[NUM_MOD][NUM_STUDENTS];
	// NOTE: might be a good idea to change to a smaller number if you
	//       too lazy to enter so many numbers
	
	int s = 0;
	int m = 0;
	for(s = 0; s < NUM_STUDENTS; s++)
	{
		for(m = 0; m < NUM_MOD; m++)
		{
			printf("Student %d, module %d: ", s+1, m+1);
			
			int mark = 0;
			scanf("%d", &mark);
			marks[m][s] = mark;
		}
	}
	
	printf("\n\nThe marks entered:\n");
	for(m = 0; m < NUM_MOD; m++)
	{
		for(s = 0; s < NUM_STUDENTS; s++)
		{
			printf("Student %d, module %d: %d\n", s+1, m+1, marks[m][s]);
		}
	}
	
	return 0;
}*/


//-------------------------------- example 8 ----------------------------------
/*#include <stdio.h>

int main(void)
{
	const int NUM_MOD = 6;
	const int NUM_STUDENTS = 10;
	int marks[NUM_MOD][NUM_STUDENTS];
	// NOTE: might be a good idea to change to a smaller number if you
	//       too lazy to enter so many numbers
	
	int s = 0;
	int m = 0;
	for(s = 0; s < NUM_STUDENTS; s++)
	{
		for(m = 0; m < NUM_MOD; m++)
		{
			printf("Student %d, module %d: ", s+1, m+1);
			
			int mark = 0;
			scanf("%d", &mark);
			marks[m][s] = mark;
		}
	}
	
	for(m = 0; m < NUM_MOD; m++)
	{
		printf("Module %d: ", m+1);
		for(s = 0; s < NUM_STUDENTS; s++)
		{
			if(s == NUM_STUDENTS - 1)
			{
				printf("%d", marks[m][s]);
			}
			else
			{
				printf("%d, ", marks[m][s]);
			}
		}
		printf("\n");
   }
   
   // NOTE: same as example 7 except the output is in a table format
   //       instead of a long list
   
   return 0;
}*/


//-------------------------------- example 9 ----------------------------------
/*#include <stdio.h>

int main(void)
{
	const int NUM_MOD = 2;
	const int NUM_STUDENTS = 3;
	int marks[NUM_MOD][NUM_STUDENTS];
	
	int s = 0;
	int m = 0;
	for(s = 0; s < NUM_STUDENTS; s++)
	{
		for(m = 0; m < NUM_MOD; m++)
		{
			printf("Student %d, module %d: ", s+1, m+1);
			
			int mark = 0;
			scanf("%d", &mark);
			marks[m][s] = mark;
		}
	}
	
	for(m = 0; m < NUM_MOD; m++)
	{
		printf("Module %d: ", m+1); 
		for(s = 0; s < NUM_STUDENTS - 1; s++)
		{
			printf("%d, ", marks[m][s]);
		}
		
		printf("%d", marks[m][NUM_STUDENTS - 1]);
		printf("\n");
	}
	
	// NOTE: same as example 8 except the for loop is structured slightly
	//       differently
	
	return 0;
}*/


//-------------------------------- example 10 ----------------------------------
/*#include <stdio.h>

int main(void)
{
	int nColumn = 80;
	int nRow = 25;
	int canvas[nRow][nColumn];
	
	int r = 0;
	int c = 0;
	for(r = 0; r < nRow; r++)
	{
		for(c = 0; c < nColumn; c++)
		{
			canvas[r][c] = ' ';
		}		
	}
	
	canvas[10][13] = ',';
	canvas[10][14] = 'o';
	canvas[10][15] = '8';
	canvas[10][16] = 'o';
	canvas[10][17] = ',';
	canvas[10][19] = ',';
	canvas[10][20] = 'o';
	canvas[10][21] = '8';
	canvas[10][22] = 'o';
	canvas[10][23] = ',';
	
	canvas[11][11] = ',';
	canvas[11][12] = '8';
	canvas[11][13] = '8';
	canvas[11][14] = '8';
	canvas[11][15] = '8';
	canvas[11][16] = '8';
	canvas[11][17] = '8';
	canvas[11][18] = ',';
	canvas[11][19] = '8';
	canvas[11][20] = '8';
	canvas[11][21] = '8';
	canvas[11][22] = '8';
	canvas[11][23] = '8';
	canvas[11][24] = '8';
	canvas[11][25] = ',';
	
	canvas[12][11] = '8';
	canvas[12][12] = '8';
	canvas[12][13] = '8';
	canvas[12][14] = '8';
	canvas[12][15] = '8';
	canvas[12][16] = '8';
	canvas[12][17] = '8';
	canvas[12][18] = '8';
	canvas[12][19] = '8';
	canvas[12][20] = '8';
	canvas[12][21] = '8';
	canvas[12][22] = '8';
	canvas[12][23] = '8';
	canvas[12][24] = '8';
	canvas[12][25] = '8';
	
	canvas[13][11] = '8';
	canvas[13][12] = '8';
	canvas[13][13] = '8';
	canvas[13][14] = '8';
	canvas[13][15] = '8';
	canvas[13][16] = '8';
	canvas[13][17] = '8';
	canvas[13][18] = '8';
	canvas[13][19] = '8';
	canvas[13][20] = '8';
	canvas[13][21] = '8';
	canvas[13][22] = '8';
	canvas[13][23] = '8';
	canvas[13][24] = '8';
	canvas[13][25] = '8';
	
	canvas[14][11] = ',';
	canvas[14][12] = '8';
	canvas[14][13] = '8';
	canvas[14][14] = '8';
	canvas[14][15] = '8';
	canvas[14][16] = '8';
	canvas[14][17] = '8';
	canvas[14][18] = '8';
	canvas[14][19] = '8';
	canvas[14][20] = '8';
	canvas[14][21] = '8';
	canvas[14][22] = '8';
	canvas[14][23] = '8';
	canvas[14][24] = '8';
	canvas[14][25] = ',';
	
	canvas[15][13] = ',';
	canvas[15][14] = '8';
	canvas[15][15] = '8';
	canvas[15][16] = '8';
	canvas[15][17] = '8';
	canvas[15][18] = '8';
	canvas[15][19] = '8';
	canvas[15][20] = '8';
	canvas[15][21] = '8';
	canvas[15][22] = '8';
	canvas[15][23] = ',';
	
	canvas[16][15] = ',';
	canvas[16][16] = '8';
	canvas[16][17] = '8';
	canvas[16][18] = '8';
	canvas[16][19] = '8';
	canvas[16][20] = '8';
	canvas[16][21] = ',';
	
	canvas[17][17] = ',';
	canvas[17][18] = '8';
	canvas[17][19] = ',';
	canvas[17][25] = 'P';
	canvas[17][26] = 'r';
	canvas[17][27] = 'a';
	canvas[17][28] = 'p';
	canvas[17][29] = 'a';



	
	for(r = 0; r < nRow; r++)
	{
		for(c = 0; c < nColumn; c++)
		{
			printf("%c", canvas[r][c]);
		}
		printf("\n");
	}
	
	return 0;
}*/


//-------------------------------- example 11 ----------------------------------
/*#include <stdio.h>

int main(void)
{
	int count = 0;
	printf("Please enter number of input: ");
	scanf("%d", &count);
	
	int myInt[count];
	int i = 0;
	for(i = 0; i < count; i++)
	{
		printf("Please enter an input: ");
		scanf("%d", &myInt[i]);
	}
	
	printf("You have entered:\n");
	for(i = 0; i < count; i++)
	{
		
		printf("%d ", myInt[i]);
	}
	printf("\n");
	
	// DIY: enter number in ascending order, and see the output which 
	//      should produce descending order of your input
	
	int min = 0;
	int index = -1;
	int temp = 0;
	int j = 0;
	
	// NOTE: an example for descending sort
	for(i = 0; i < count; i++)
	{
		index = i;
		min = myInt[i];
		for(j = i+1; j < count; j++)
		{
			if(min < myInt[j])
			{
				min = myInt[j];
				index = j;
				// find the location of the smallest unsorted number
			}
		}
		
		if(index != i)
		{
			temp = myInt[i];
			myInt[i] = myInt[index];
			myInt[index] = temp;
			// swap the smallest unsorted number
		}
	}
	
	// DIY: rewrite this program to do an ascending sort
	
	printf("Sorted array:\n");
	for(i = 0; i < count; i++)
	{
		
		printf("%d ", myInt[i]);
	}
	printf("\n");
	
	return 0;
}*/


//-------------------------------- example 12 ----------------------------------
/*#include <stdio.h>

int main(void)
{
	int count = 0;
	printf("Please enter number of input: ");
	scanf("%d", &count);
	
	int myInt[count];
	int i = 0;
	for(i = 0; i < count; i++)
	{
		printf("Please enter an input: ");
		scanf("%d", &myInt[i]);
	}
	
	printf("You have entered:\n");
	for(i = 0; i < count; i++)
	{
		
		printf("%d ", myInt[i]);
	}
	printf("\n");
	
	int temp = 0;
	int j = 0;
	for(i = 0; i < count; i++)
	{
		for(j = 0; j < (count - 1); j++)
		{
			if(myInt[j] < myInt[(j + 1)])
			{
				temp = myInt[j];
				myInt[j] = myInt[(j + 1)];
				myInt[(j + 1)] = temp;
			}
		}
	}
	
	printf("Sorted array:\n");
	for(i = 0; i < count; i++)
	{
		
		printf("%d ", myInt[i]);
	}
	printf("\n");
	
	return 0;
}*/


//-------------------------------- example 13 ----------------------------------
/*#include <stdio.h>

int main(void)
{
	int count = 0;
	printf("Please enter number of input: ");
	scanf("%d", &count);
	
	int myInt[count];
	int i = 0;
	for(i = 0; i < count; i++)
	{
		printf("Please enter an input: ");
		scanf("%d", &myInt[i]);
	}
	
	printf("You have entered:\n");
	for(i = 0; i < count; i++)
	{
		
		printf("%d ", myInt[i]);
	}
	printf("\n");
	
	int hunt = 0;
	printf("Please enter the desired number: ");
	scanf("%d", &hunt);
	
	int index = -1;
	for(i = 0; i < count; i++)
	{
		if(hunt == myInt[i])
		{
			index = i;
			break;
		}
	}
	
	if(index != -1)
	{
		printf("Number is found at index %d\n", index);
	}
	else
	{
		printf("Number is not found\n");
	}
	
	return 0;
}*/


