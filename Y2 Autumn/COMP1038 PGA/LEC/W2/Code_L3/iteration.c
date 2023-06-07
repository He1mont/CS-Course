//-------------------------------- example 1 ----------------------------------
/*#include <stdio.h>

int main(void)
{
	int input = 0;
	int sum = 0;
	
	printf("Please enter an input: ");
	scanf("%d", &input);
	
	sum = sum + input;
	
	printf("Please enter an input: ");
	scanf("%d", &input);
	
	sum = sum + input;
	
	printf("The sum of two numbers is %d\n", sum);
	
	return 0;
}*/

//-------------------------------- example 2 ----------------------------------
/*#include <stdio.h>

int main(void)
{
	int counter = 0;
	int input = 0;
	int sum = 0;
	
	for(counter = 0; counter < 2; counter++)
	{
		printf("Please enter an input: ");
		scanf("%d", &input);
		
		sum = sum + input;
	}
	
	// DIY: try changing 2 to 10, compile, run the program, 
	//      and compare the output
	
	printf("The sum of two numbers is %d\n", sum);
	
	return 0;
}*/

//-------------------------------- example 3 ----------------------------------
/*#include <stdio.h>

// NOTE: this example is the same as example 1 but with a DIY

int main(void)
{
	int input = 0;
	int sum = 0;
	
	printf("Please enter an input: ");
	scanf("%d", &input);
	
	sum = sum + input;
	
	printf("Please enter an input: ");
	scanf("%d", &input);
	
	sum = sum + input;
	
	printf("The sum of two numbers is %d\n", sum);
	
	// DIY: try enter 1 and 2 at the first prompt and second prompt 
	//      respectively, then try to enter 1 2 at the first prompt,
	//      compare the output
	
	return 0;
}*/

//-------------------------------- example 4 ----------------------------------
/*#include <stdio.h>

// DIY: 
// - try to enter two integers e.g. 2 3 (note the space between 2 and 3) 
//   at the first prompt and then enter two integers with a comma between 
//   the two integers at the second prompt e.g. 2,3 (note the comma between 
//   2 and 3), and see the output
// - try to run the program again but this time enters two integers e.g. 2,3 
//   (note the comma between 2 and 3) at the first prompt and then see what 
//   happen


int main(void)
{
	int myInt1 = 0;
	int myInt2 = 0;
	int myScanf = 0;
	
	printf("%s", "Please enter two integers e.g. 2 3: ");
	myScanf = scanf("%d %d", &myInt1, &myInt2);
	
	printf("\nYou have entered %d and %d, the scanf returned %d\n", 
		myInt1, myInt2, myScanf);
	
	myInt1 = 0;
	myInt2 = 0;
	
	printf("%s", "Please enter two integers e.g. 2,3: ");
	myScanf = scanf("%d,%d", &myInt1, &myInt2);
	// note the formatting of the input in scanf
	
	printf("\nYou have entered %d and %d, the scanf returned %d\n", 
		myInt1, myInt2, myScanf);
	
	return 0;
	
}*/

//-------------------------------- example 5 ----------------------------------
/*#include <stdio.h>

int main(void)
{
	int day = 0;
	int month = 0;
	int year = 0;
	int count = 0;
	
	printf("Please enter your date of birth (dd/mm/yyyy): ");
	count = scanf("%d/%d/%d", &day, &month, &year);
	// NOTE: the '/' in the scanf statement
	
	printf("There are %d correctly formatted values\n", count);
	printf("The values are %d, %d and %d\n", day, month, year);
	
	// DIY: enter 01/02/1234
	//      run the program again but this time enter 01 02 1234
	//      compare the output of the two runs
	
	// DIY: Replace '/' in line 469 with a space, compile, 
	//      run the program.
	//      This time enter 01 02 1234, and compare the output with 
	//      the previous run.
	
	return 0;
}*/

//-------------------------------- example 6 ----------------------------------
/*#include <stdio.h>

int main(void)
{
	int counter = 0;
	int input = 0;
	int sum = 0;
	
	while(counter < 2)
	{
		printf("Please enter an input: ");
		scanf("%d", &input);
		
		sum = sum + input;
		counter = counter + 1;
	}
	
	printf("The sum of two numbers is %d\n", sum);
	
	// DIY: run example 2 and compare the output with this example 6
	
	return 0;
}*/

//-------------------------------- example 7 ----------------------------------
/*#include <stdio.h>

int main(void)
{
	int input = 0;
	int sum = 0;
	
	do
	{
		printf("Please enter an input: ");
		scanf("%d", &input);
		
		if(input > 0)
		{
			sum = sum + input;
		}
		
	}while(input > 0);
	
	printf("The sum of the input numbers is %d\n", sum);
	
	// DIY: try enter 1 then 2 then 0,
	//      run the program again but this time enter 1 then 2 then 
	//      enter 3 other numbers and type 0 to stop the summation,
	//      compare the output of the two runs
	
	return 0;
}*/

//-------------------------------- example 8 ----------------------------------
/*#include <stdio.h>

int main(void)
{
	int counter = 0;
	int input = 0;
	int sum = 0;
	int limit = 0;
	
	printf("Please enter the number of input: ");
	scanf("%d", &limit);
	
	while(counter < limit)
	{
		printf("Please enter an input: ");
		scanf("%d", &input);
		
		sum = sum + input;
		counter = counter + 1;
	}
	
	printf("The sum of the input numbers is %d\n", sum);
	
	// DIY: enter 5 and then enter the same numbers you have entered
	//      in example 7, and compare the output
	
	return 0;
}*/

//-------------------------------- example 9 ----------------------------------
/*#include <stdio.h>

int main(void)
{
   int counter = 0;
	int input = 0;
	int sum = 0;
	int limit = 0;
	
	printf("Please enter the number of input: ");
	scanf("%d", &limit);
	
	while(counter < limit);
	{
		// DIY: run the program once and note that the program will never
		//      go pass line 215.
		//      Now press ctrl c (Windows user) or press ctrl z (Linux),
		//      delete the ';' after '(counter < limit)', compile,
		//      run the program again and compare the output
		printf("Please enter an input: ");
		scanf("%d", &input);
		
		sum = sum + input;
		counter = counter + 1;
	}
	
	printf("The sum of the input numbers is %d\n", sum);
	
	return 0;
}*/

//-------------------------------- example 10 ----------------------------------
/*#include <stdio.h>

int main(void)
{
	int keepGoing = 1;
	
	do
	{
		// Print the menu and get the user's choice.
		printf("1) Add\n");
		printf("2) Multiply\n");
		printf("3) Mod\n");
		printf("4) Quit\n");
		printf("Enter option: ");
		
		int option = 0;
		scanf("%d", &option);
		
		if(option == 1)
		{
			// Add 2 numbers.
			int n1 = 0;
			printf("Enter first number: ");
			scanf("%d", &n1);
			
			int n2 = 0;
			printf("Enter second number: ");
			scanf("%d", &n2);
			
			int ans = n1 + n2;
			printf("The answer is %d\n\n", ans);
		}
		else if(option == 2)
		{
			// Multiply 2 numbers.
			int n1 = 0;
			printf("Enter first number: ");
			scanf("%d", &n1);
			
			int n2 = 0;
			printf("Enter second number: ");
			scanf("%d", &n2);
			
			int ans = n1 * n2;
			printf("The answer is %d\n\n", ans);
		}
		else if(option == 3)
		{
			// Modulus
			int n1 = 0;
			printf("Enter first number: ");
			scanf("%d", &n1);
			
			int n2 = 0;
			printf("Enter second number: ");
			scanf("%d", &n2);
			
			int ans = n1 % n2;
			printf("The answer is %d\n\n", ans);
		}
		else if(option == 4)
		{
			// Quit
			keepGoing = 0;
		}
   }while(keepGoing); 

   return 0;   
}*/

//-------------------------------- example 11 ----------------------------------
/*#include <stdio.h>

int main(void)
{
	int input = 0;
	int sum = 0;
	int count = 0;
	
	do
	{
		printf("Please enter an input (-1 to quit): ");
		scanf("%d", &input);
		
		if(input == -1)
		{
			break;
		}
		
		sum = sum + input;
		count++;
		
		// DIY: move line 323 and 324 to before if statement in line 319,
		//      compile, run the program and compare the result
		
		// NOTE: the location where you 'break' matters!!
		
	}while(input != -1);
	
	printf("The sum of the input numbers is %d\n", sum);
	printf("The average of the input numbers is %d\n", (sum / count));
	
	return 0;
}*/


//-------------------------------- example 12 ----------------------------------
/*#include <stdio.h>

int main(void)
{
	int input = 0;
	int sum = 0;
	int count = 0;
	
	while(1)
	{	
		// NOTE: while(1) is a very poor programming practice, please
		//       never this (This is for demonstration purpose only) 
		
		// DIY: try changing 1 to 0, compile, run the program 
		//      and compare the output
		
		printf("Please enter an input (-1 to quit): ");
		scanf("%d", &input);
		
		if(input == -1)
		{
			break;
		}
		sum = sum + input;
		count++;
	}
	
	printf("The sum of the input numbers is %d\n", sum);
	printf("The average of the input numbers is %.2f\n", 
		((float)sum / count));
	
	// NOTE: the difference in output between example 11 and example 12
	//       because of typecasting '(float)'
	
	return 0;
}*/

//-------------------------------- example 13 ----------------------------------
/*#include <stdio.h>

int main(void)
{
	int input = 0;
	int sum = 0;
	int count = 0;
	int quit = 0;
	
	while(quit == 0)
	{	
		// NOTE: this example 13 is similar to example 12 except there 
		//       is now no 'while(1)' i.e. better programming practice
		
		printf("Please enter an input (-1 to quit): ");
		scanf("%d", &input);
		
		if(input == -1)
		{
			quit = 1;
			break;
		}
		sum = sum + input;
		count++;
	}
	
	printf("The sum of the input numbers is %d\n", sum);
	printf("The average of the input numbers is %.2f\n", 
		((float)sum / count));
	
	return 0;
}*/

//-------------------------------- example 14 ----------------------------------
/*#include <stdio.h>

int main(void)
{
	int i = 0;
	
	for(i = 1; i < 10; i++)
	{	
		if(i == 5)
		{
			break;
		}
		printf("%d ", i);
	}
	
	printf("End = %d\n", i);
	
	return 0;
}*/

//-------------------------------- example 15 ----------------------------------
/*#include <stdio.h>

int main(void)
{
	int i = 0;
	
	for(i = 1; i < 10; i++)
	{	
		if(i <= 5)
		{
			continue;
		}
		printf("%d ", i);
	}
	
	printf("End = %d\n", i);
	
	// NOTE: the difference between break and continue in example 14 
	//       and this example 15
	
	return 0;
}*/


//-------------------------------- example 16 ----------------------------------
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
   
   // NUM_MONTHS = 13;
   
   // DIY: uncomment the statement above, compile, run the program,
   //      note the error on your output

   printf("Total is %d\n", total);
   printf("Average is %d\n", total / NUM_MONTHS);
   
   return 0;
}*/

//-------------------------------- example 17 ----------------------------------
/*#include <stdio.h>

#define NUM_MONTHS 12

int main(void)
{
   int total = 0;

   for(int i = 0; i < NUM_MONTHS; i++)
   {
      int x = 0;
      printf("Enter month %d: ", i + 1);
      scanf("%d", &x);
      total = total + x;
   }

   printf("Total is %d\n", total);
   printf("Average is %d\n", total / NUM_MONTHS);
   
   // NOTE: the output between this example 17 and example 16 should 
   //       be exactly the same
   
   return 0;
}*/

//-------------------------------- example 18 ----------------------------------
/*#include <stdio.h>

#define SIZE 10 + 10

int main(void)
{
   int total = 0;
   
   printf("10 + 10 = %d\n", SIZE);
   
   printf("10 + 10 * 10 + 10 = %d\n", SIZE * SIZE);
   
   // NOTE: how 'define' replace the content with string (uncalculated) 
   
   return 0;
}*/




