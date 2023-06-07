//-------------------------------- example 1 ----------------------------------
/*void main(void)
{
	
}*/

//-------------------------------- example 2 ----------------------------------
/*#include <stdio.h>

int main(void)
{
	int number = 0;
	
	printf("Current number is: %d\n", number);
	
	printf("Please enter a new number: ");
	scanf("%d", &number);
	// DIY: remove the '&' sign, compile, run the program
	//      and check the error code afterwards
	
	printf("You've entered: %d\n", number);
	
	return 0;

}*/

//-------------------------------- example 3 ----------------------------------
/*#include <stdio.h>

void myPrint(void);
int myReturn(void);

int main(void)
{
	int number = 0;
	
	myPrint();
	
	printf("Current number is: %d\n", number);	
	
	number = myReturn();	
	
	printf("The number is now: %d\n", number);
	
	return 0;

}

void myPrint(void)
{
	printf("Hello There !!\n");
}

int myReturn(void)
{
	return 5;
}*/

//-------------------------------- example 4 ----------------------------------
/*#include <stdio.h>

int main(void)
{
	int counter = 0;
	// DIY: remove ' = 0', compile, run the programe
	//      and compare the output with and without the initialisation
	int number = 0;
	
	while(number < 1)
	{
		printf("Please enter a new number: ");
		scanf("%d", &number);
		
		counter = counter + 1;
	}
	
	if(counter > 1)
	{
		printf("User has entered %d new numbers\n", counter);
	}
	else
	{
		printf("User has entered %d new number\n", counter);
	}
	
	return 0;

}*/

//-------------------------------- example 5 ----------------------------------
/*#include <stdio.h>

int main(void)
{
	printf("Roses are red");
	printf("Violet are blue");
	printf("Sugar is sweet");
	printf("And so are you!");	
	// DIY: add \n at the end of the sentences before the second "
	//      compile, run the program, and compare the output 
	//      with and without \n
	
	printf("\n\n%c", 'A');
	printf("\t%d", 'A');
	// NOTE: the output of when different format specifiers are used
	//       on the same input i.e. 'A'
	
	return 0;
}*/

//-------------------------------- example 6 ----------------------------------
/*#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
   int x = 0;
   int y = 0;
   int z = 0;
   // DIY: try 3, 4, 5 for x, y and z
   //      compile, run and compare the output with 1, 2, 3

   printf("Enter value for x: ");
   scanf("%d", &x);
   if(x < 1)
   {
      printf("Invalid value\n");
      exit(1);
	  // NOTE: 'exit' quits the program whereas 
	  //       'return' leaves the current function 
   }

   printf("Enter value for y: ");
   scanf("%d", &y);
   if(y < 1)
   {
      printf("Invalid value\n");
      exit(1);
   }
   
   printf("Enter value for z: ");
   scanf("%d", &z);
   if(z < 1)
   {
      printf("Invalid value\n");
      exit(1);
   }
   
   int lhs = x * x + y * y;
   int rhs = z * z;

   if(lhs == rhs)
   {
      printf("Right angled triangle\n");
   }
   else
   {
      printf("Not right angled, %d does not equal %d\n", lhs, rhs );
   }

}*/

//-------------------------------- example 7 ----------------------------------
//int main(void)
//{
	/* This program calculate the remainder if division, 
	   and return zero to the shell */
	   
//	int i = (10 % 3);
	
	// The line belows return zero to the shell that calls the program
//	return 0;
//}

//-------------------------------- example 8 ----------------------------------
/*#include <stdio.h>

void doSomething();
void doSomethingElse();
void doDefaultThing();

int main(void)
{
	int value = 0;
	// DIY: try change the initialised value to 1, 2, 3
	//      compile, run the program and compare the ouput
	
	switch(value)
	{
		case 1:
			doSomething();
			//break;
			// DIY: uncomment 'break', initialise 'value' to 1
			//      compile, run the program and 
			//      compare the output when 'break' is and is not commented 
			
		case 2:
			doSomethingElse();
			break;
		
		default:
			doDefaultThing();
			break;
	}
	
	return 0;
}

void doSomething()
{
	printf("Do Something\n");
}

void doSomethingElse()
{
	printf("Do Something Else\n");
}

void doDefaultThing()
{
	printf("Do Default thing\n");
}*/

//-------------------------------- example 9 ----------------------------------
/*#include <stdio.h>

int main(void)
{
	int a = 0;
	
	if(a = 1)
	{
		// DIY: add an extra '=' in front of the existing '='
		//      compile, run the program and compare the output
		printf("a is NOT equal to zero\n");
	}
	else
	{
		printf("a is equal to zero\n");
	}

	return 0;
}*/

//-------------------------------- example 10 ----------------------------------
/*#include <stdio.h>

int main(void)
{
	int b = 1.25;
	double c = 1.25;
	
	printf("The sum of b and c is %.2f\n", (c + b));
	// DIY: delete '.2', compile, run the program and compare the output
	
	return 0;
}*/

//-------------------------------- example 11 ----------------------------------
/*#include <stdio.h>

int main(void)
{
	int d = 1;
	int e = 2;
	int f = 3;
	
	printf("d + e * f = %d\n", (d + e * f));
	printf("(d + e) * f = %d\n", ((d + e) * f));
	
	return 0;
}*/

//-------------------------------- example 12 ----------------------------------
/*#include <stdio.h>

int main(void)
{
	printf("Hello World!!\n");
	Printf(“Hello World!!\n”);
	
	return 0;	
}*/

//-------------------------------- example 13 ----------------------------------
/*#include <stdio.h>

int main(void)
{
	int arr[2];
	arr[0] = 0;
	arr[1] = 1;
	
	int i = 0;
	for(i = 0; i < 10; i++)
	{	
		// DIY: try change '3' to 10, compile, run the program
		//      and compare the output
		printf("%d\n", arr[i]);
	}
	
	return 0;
}*/

