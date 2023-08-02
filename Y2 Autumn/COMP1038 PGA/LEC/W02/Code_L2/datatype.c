//-------------------------------- example 1 ----------------------------------
/*#include <stdio.h>

int main(void)
{
	int auto = 0;
	// NOTE: the colour of 'auto' is the same as data type 'int'
	
	printf("auto = %d\n", auto);
	
	return 0;
}*/

//-------------------------------- example 2 ----------------------------------
/*#include <stdio.h>

int main(void)
{
	int id = 0;
	
	printf("Current ID number is %d\n", id);
	printf("Current ID number is %p\n", &id);
	
	printf("\n\nEnter your ID number: ");
	scanf("%d", &id);
	
	printf("\n\nCurrent ID number is %d\n", id);
	printf("Current ID number is %p\n", &id);
	// NOTE: the value of 'id' has changed but not the memory address
	
	return 0;
}*/

//-------------------------------- example 3 ----------------------------------
/*#include <stdio.h>

int main(void)
{
	int a = 0;
	int b = 0;
	int c = 0;
	
	a = 100, b = a + 100, c = b + 100;	
		
	printf("a + b + c = %d\n", (a + b + c));
	
	
	a = 0;
	b = 0;
	c = 0;
	
	c = b + 100, b = a + 100, a = 100;
	
	printf("a + b + c = %d\n", (a + b + c));
	// NOTE: compare the output of the two printfs
	
	return 0;
}*/

//-------------------------------- example 4 ----------------------------------
/*#include <stdio.h>

int main(void)
{
	unsigned char a = 250;
	int b = (int)a;
	int counter = 0;
	
	printf("a is %d and b is %d\n", a, b);
	
	while(counter < 10)
	{
		a = a + 1;
		counter = counter + 1;
		printf("%d + %d = %d\n", b, counter, a);
	}
	// NOTE: that 'a' doesn't go beyond 255
	
	
	a = 5;
	b = (int)a;
	counter = 0;
	
	printf("a is %d and b is %d\n", a, b);
	
	while(counter < 10)
	{
		a = a - 1;
		counter = counter + 1;
		printf("%d - %d = %d\n", b, counter, a);
	}
	// NOTE: that 'a' doesn't go below 0
		
		
	return 0;
}*/

//-------------------------------- example 5 ----------------------------------
/*#include <stdio.h>
#include <limits.h>

int main(void)
{
	unsigned char tickets = 254;
	int new = 0;
	char invalid = 1;
	
	do
	{
		printf("Please enter the number of tickets required: ");
		scanf("%d", &new);

		if(new <= 0)
		{
			printf("Please enter a valid number!\n");
		}
		else if((new + tickets) > UCHAR_MAX)
		{
			printf("Only %d ticket(s) left\n", (UCHAR_MAX - tickets));			
		}
		else
		{
			invalid = 0;
		}
		
	}while(invalid == 1);
	
	printf("You've bought %d tickets\n", new);

	
	return 0;
}*/

//-------------------------------- example 6 ----------------------------------
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
	
	printf("\n\n%10c", 'A');
	printf("\t%d", 'A');
	
	printf("\n%d", 1.23456789);
	// NOTE: what happen when you display floating number using %d
	printf("\t%f", 1.23456789);
	printf("\t%.2f", 1.23456789);
	printf("\t%.4f", 1.23456789);
	
	short myshort = 32768;
	printf("\n%d", myshort);
	// DIY: change 32768 to 32769, compile, run the program 
	//      and compare the output
	
	printf("\n%%");
	// NOTE: the number of '%' shown on the output
	
	return 0;
}*/

//-------------------------------- example 7 ----------------------------------
/*#include <stdio.h>

int main(void)
{
	printf("\n%.9f", 1.23456789);
	printf("\n%.8f", 1.23456789);
	printf("\n%.7f", 1.23456789);
	printf("\n%.6f", 1.23456789);
	printf("\n%.5f", 1.23456789);
	printf("\n%.4f", 1.23456789);
	printf("\n%.3f", 1.23456789);
	printf("\n%.2f", 1.23456789);
	printf("\n%.1f", 1.23456789);
	printf("\n%.0f", 1.23456789);
	
	printf("\n\n%f", 1.23456789);
	
	printf("\n\n%11.9f", 1.23456789);
	printf("\n%11.8f", 1.23456789);
	printf("\n%11.7f", 1.23456789);
	printf("\n%11.6f", 1.23456789);
	printf("\n%11.5f", 1.23456789);
	printf("\n%11.4f", 1.23456789);
	printf("\n%11.3f", 1.23456789);
	printf("\n%11.2f", 1.23456789);
	printf("\n%11.1f", 1.23456789);
	printf("\n%11.0f", 1.23456789);
	
	return 0;
}*/

//-------------------------------- example 8 ----------------------------------
/*#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
   int wind = -1;

   printf("Enter wind speed (km/h): ");
   scanf("%d", &wind);

   if(wind < 0)
   {
      printf("Impossible wind speed!\n");
      exit(1);
	  // NOTE: 'exit' quits the program whereas 
	  //       'return' leaves the current function 
   }

   printf("Line 223\n");
   if(wind < 63)
   {
      printf("Tropical Depression\n");
      exit(0);
   }
   
   printf("Line 230\n");
   if(wind < 119)
   {
      printf("Tropical Storm\n");
      exit(0);
   }
   
   printf("Line 237\n");
   if(wind < 241)
   {
      printf("Typhoon\n");
      exit(0);
   }
   
   printf("Line 244\n");
   printf("Super Typhoon\n");
   
   // DIY: comment out all the 'exit', compile, run the program 
   //      and compare the output
   
   return 0;
}*/

//-------------------------------- example 9 ----------------------------------
/*#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
   int wind = -1;

   printf("Enter wind speed (km/h): ");
   scanf("%d", &wind);

   if(wind < 0)
   {
	   printf("Impossible wind speed!\n");
	   exit(1);
   }
   else
   {
	   if(wind < 63)
	   {
		   printf("Tropical Depression\n");
		   exit(0);
	   }	   
	   else if(wind < 119)
	   {
		   printf("Tropical Storm\n");
		   exit(0);
	   }
	   
	   else if(wind < 241)
	   {
		   printf("Typhoon\n");
		   exit(0);
	   }
	   else
	   {
		   printf("Super Typhoon\n");
		   exit(0);
	   }	   
   }
   
   return 0;
}*/

//-------------------------------- example 10 ----------------------------------
/*#include <stdio.h>

int main(void)
{
	int A = 10;
	int B = 20;
	int C = 0;
	
	// if-else statement
	if(A > B)
	{
		C = A - B;		
	}
	else
	{
		C = B - A;
	}	
	printf("The difference between A and B is %d\n", C);
	
	// conditional operator
	(A > B) ? (C = A - B): (C = B - A);
	printf("The difference between A and B is %d\n", C);
		
	// switch statement
	C = A - B;
	switch((int)(C >= 0))
	{
		case 0:
			printf("The difference between A and B is %d\n", (C * -1));
			break;
		case 1:
			printf("The difference between A and B is %d\n", C);
			break;
		default:
			printf("Error!!\n");
			break;
	}
		
	return 0;
}*/

//-------------------------------- example 11 ----------------------------------
/*#include <stdio.h>

int main(void)
{
	int a = 2;
	// DIY: change 2 to 3, compile, run the program 
	//      and compare the output
	
	(a > 3) ? printf("a is more than 3\n") : 
		(a > 2) ? printf("a is more than 2\n") :
			printf("a equals to 2\n");
	
	if(a > 3)
	{
		printf("a is more than 3\n");
	}
	else if(a > 2)
	{
		printf("a is more than 2\n");
	}
	else
	{
		printf("a equals to 2\n");
	}
	// NOTE: the clarity between the two example selection statements
	
	return 0;
}*/

//-------------------------------- example 12 ----------------------------------
/*#include <stdio.h>

int main(void)
{
	int p = 20;
	int q = 9;
	int r = 1;
	int x = 2;
	int y = 3;
	int w = 4;
	int z = 5;
	int a = 6;
	int b = 7;
	int c = 8;
	
	printf("%d\n", p * r % q + w / x - y);
	
	printf("%d\n", a * x * x + b * x + c);
	
	// DIY: calculate the results before trying to run this program 
	//      to check that you do understand the operator precedence
	
	return 0;
}*/

//-------------------------------- example 13 ----------------------------------*#include <stdio.h>
/*#include <stdio.h>
int main(void)
{
	int a = 10;
	int b = 20;
	int c = 0;
	
	c = (a >= 10) && (++b >= 15);
	
	printf("a = %d, b = %d, and c = %d\n", a, b, c);
	// NOTE: what happen to b when the first clause is true
	
	a = 10;
	b = 20;
	c = 0;
	
	c = (a > 10) && (++b >= 15);
	
	printf("a = %d, b = %d, and c = %d\n", a, b, c);
	// NOTE: what happen to b when the first clause is false
		
	return 0;
}*/

//-------------------------------- example 14 ----------------------------------
/*#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char *argv[])
{
   int x = 0;
   int y = 0;
   int z = 0;
   // DIY: try using 3, 4, 5, compile, run the program 

   printf("Enter value for x: ");
   scanf("%d", &x);
   if(x < 1)
   {
      printf("Invalid value\n");
      exit(1);
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
   
   printf("x^2 = %lf, y^2 = %lf, z^2 = %lf\n", 
      pow(x, 2), pow(y, 2), pow(z, 2));
   // NOTE: the output of 'pow' is double
   
   // example 1
   int lhs = pow(x, 2) + pow(y, 2);
   int rhs = pow(z, 2);
   // DIY: change 'rhs' from int to double, compile, run the program
   //      and compare the output between int and double

   if(lhs == rhs)
   {
	   printf("Example 1: Right angled triangle\n");
   }
   else
   {
	   printf("Example 1: Not right angled, %d does not equal %d\n", 
	      lhs, rhs);
	   // NOTE: compare the output for 'rhs' and pow(z, 2)
   }
   
   
   
   // example 2
   if(z == sqrt(pow(x, 2) + pow(y, 2)))
   {
	   // NOTE: the output of 'sqrt' is double
       printf("Example 2: Right angled triangle\n");
   }
   else
   {
	   printf("Example 2: Not right angled, %d does not equal %d\n", 
	      lhs, rhs );
   }
   
   // example 3
   lhs = (x * x) + (y * y);
   rhs = (z * z);

   if(lhs == rhs)
   {
	   printf("Example 3: Right angled triangle\n");
   }
   else
   {
	   printf("Example 3: Not right angled, %d does not equal %d\n", 
	      lhs, rhs);
	   // NOTE: compare the output for 'rhs' and (z * z)
   }
   
   return 0;
}*/

//-------------------------------- example 15 ----------------------------------
/*#include <stdio.h>
#include <math.h>

int main(int argc, char *argv[])
{
   double x, y, z;
   // DIY: try different right angled triangle
   //      e.g. 5, 12, 13; 
   //           14, 48, 50; 
   //           21, 72, 75;
   //           4, 6, 7.211102550927979;
   //           4, 6, 7.21110255092797;
   //      compile, run the program, and compare the output

   printf("Please enter side x: ");
   scanf("%lf", &x);

   printf("Please enter side y: ");
   scanf("%lf", &y);

   printf("Please enter side z: ");
   scanf("%lf", &z);
   
   double x_squared = pow(x, 2);
   double y_squared = pow(y, 2);
   double z_squared = pow(z, 2);

   double diff = fabs((x_squared + y_squared) - z_squared);
   double epsilon = 0.00000000000001;
   
   if(diff < epsilon)
   {
      printf("Right-angled\n");
   }
   else
   {
      printf("Not right-angled\n");
   }
   
   if((x_squared + y_squared) == z_squared)
   {
	   printf("!!!!!!!!!!!!!!!\n");
   }
   // NOTE: best to not use == when comparing two doubles

   return 0;  
}*/

