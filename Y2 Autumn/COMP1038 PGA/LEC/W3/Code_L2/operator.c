//-------------------------------- example 1 ----------------------------------
/*#include <stdio.h>
#include <math.h> // remember to use -lm when compile

int main(void)
{
	printf("%d\n", 7 + 5 * 3 - 1);
	printf("%d\n", 7 * 4 / 2 * 5);
	
	printf("%d\n", (10 % 8));

	printf("%f\n", fmod(10.5, 8.2));
	
	printf("%d\n", 5/3);
	
	printf("%f\n", 5/3);
	// NOTE: int/int gives int as the output i.e. what you see in your
	//       output should be wrong
	
	printf("%f\n", 4.2/2.1);
	printf("%f\n", 4.2/2);
	
	printf("%d\n", 4.2/2);
	// NOTE: float/int gives float as the output i.e. what you see in your
	//       output should be wrong
	
	return 0;
}*/


//-------------------------------- example 2 ----------------------------------
/*#include <stdio.h>

int main(void)
{
	int a = 0;
	float b = 0;
	
	b = a = 10.22;
	
	printf("%d, %f\n", a, b);
	
	return 0;
}*/


//-------------------------------- example 3 ----------------------------------
/*#include <stdio.h>

int main(void)
{
	int a = 4;
	int b = 0;
	
	b = a++;
	printf("%d, %d\n", a, b);
	
	a = 4;
	b = 0;
	
	b = ++a;
	printf("%d, %d\n", a, b);
	// NOTE: the difference between a++ and ++a in the value of b
	
	a = 1, b = 2;
	int c = 3, d = 0;
	
	d = (++a) - (b--) + (--c);
	
	printf("%d, %d, %d, %d\n", a, b, c, d);
	
	a = 1, b = 2;
	c = 3, d = 0;
	
	d = (a++) - (--b) + (c--);
	
	printf("%d, %d, %d, %d\n", a, b, c, d);
	// NOTE: the difference between var++ and ++var (or var-- and --var) 
	//       in the value of d
	
	return 0;
}*/


//-------------------------------- example 4 ----------------------------------
/*#include <stdio.h>

int main(void)
{
	int a = 4;
	int b = 5;
	int c = 5;
	int d = 6;
	
	printf("%d > %d = %d\n", a, b, a > b);
	printf("%d < %d = %d\n", a, b, a < b);
	
	printf("%d <= %d = %d\n", a, b, a <= b);
	printf("%d >= %d = %d\n", d, b, d >= b);
	printf("%d >= %d = %d\n", c, b, c >= b);
	printf("%d <= %d = %d\n", c, b, c <= b);
	
	printf("%d == %d = %d\n", c, b, c == b);
	printf("%d != %d = %d\n", c, b, c != b);
	
	return 0;
}*/


//-------------------------------- example 5 ----------------------------------
/*#include <stdio.h>

int main(void)
{
	int a = 4;

	if(!a) // better to use explicit comparison i.e. a == 0
	{
		printf("a is equal to false\n");
	}
	else
	{
		printf("a is equal to true\n");
	}
	
	if(a) // better to use explicit comparison i.e. a != 0
	{
		printf("a is equal to true\n");
	}
	else
	{
		printf("a is equal to false\n");
	}
	
	if(a == 0)
	{
		printf("a is equal to false\n");
	}
	else
	{
		printf("a is equal to true\n");
	}
	
	if(a != 0)
	{
		printf("a is equal to true\n");
	}
	else
	{
		printf("a is equal to false\n");
	}
	
	
	return 0;
}*/


//-------------------------------- example 6 ----------------------------------
/*#include <stdio.h>

int main(void)
{
	int a = 4;
	int b = 2;
	
	a = (a + 6);
	printf("a = %d and b = %d\n", a, b);
	
	a = 4;
	b = 2;
	
	a += 6;
	printf("a = %d and b = %d\n", a, b);
	
	a = 4;
	b = 2;
	
	a = (a * (b + 3));
	printf("a = %d and b = %d\n", a, b);
	
	a = 4;
	b = 2;
	
	a *= (b + 3);
	printf("a = %d and b = %d\n", a, b);
	
	a = 4;
	b = 2;
	
	a = (a - (b + 8));
	printf("a = %d and b = %d\n", a, b);
	
	a = 4;
	b = 2;
	
	a -= (b + 8);
	printf("a = %d and b = %d\n", a, b);
	
	a = 4;
	b = 2;
	
	a = (a / b);
	printf("a = %d and b = %d\n", a, b);
	
	a = 4;
	b = 2;
	
	a /= b;
	printf("a = %d and b = %d\n", a, b);
	
	a = 4;
	b = 2;
	
	a = (a % (b + 1));
	printf("a = %d and b = %d\n", a, b);
	
	a = 4;
	b = 2;
	
	a %= (b + 1);
	printf("a = %d and b = %d\n", a, b);
	
	
	return 0;
}*/


//-------------------------------- example 7 ----------------------------------
/*#include <stdio.h>

int main(void)
{
	int a = 10;
	int b = 20;
	int c = 0;
	
	c = (a >= 10) && (++b >= 15);
	printf("a = %d, b = %d, and c = %d\n", a, b, c);
	
	a = 10;
	b = 20;
	c = 0;
	
	c = (a > 10) && (++b >= 15);
	printf("a = %d, b = %d, and c = %d\n", a, b, c);
	// NOTE: how second clause is not executed in the second assignment 
	//       of c because the first clause is false, therefore the 
	//       value of b is unchanged
	
	// NOTE: do not write statements like these, as they have "side effect
	//       order"
	
	return 0;
}*/


//-------------------------------- example 8 ----------------------------------
// this example is similar to example 7 but with no side effect order
/*#include <stdio.h>

int main(void)
{
	int a = 10;
	int b = 20;
	int c = 0;
	
	//c = (a >= 10) && (++b >= 15); // this is the same as example 7
	// NOTE: an example with side effect order, do not write like this
	
	++b;
	c = (a >= 10) && (b >= 15);
	printf("a = %d, b = %d, and c = %d\n", a, b, c);
	// NOTE: if your intention is to always increment b then take
	//       that out of the assignment to avoid "side effect order"
	
	a = 10;
	b = 20;
	c = 0;
	
	//c = (a > 10) && (++b >= 15); // this is the same as example 7
	// NOTE: an example with side effect order, do not write like this
	
	++b;
	c = (a > 10) && (b >= 15);
	printf("a = %d, b = %d, and c = %d\n", a, b, c);
	// NOTE: if your intention is to always increment b then take
	//       that out of the assignment to avoid "side effect order"
	
	return 0;
}*/


//-------------------------------- example 9 ----------------------------------
/*#include <stdio.h>

int main(void)
{
	int a = 1;
	int b = 2;
	int c = 0;
	
	c = (a >= 1) || (++b >= 3);
	printf("a = %d, b = %d, and c = %d\n", a, b, c);	
	// NOTE: how second clause is not executed in this assignment 
	//       of c because the first clause is true, therefore the 
	//       value of b is unchanged
	
	a = 1;
	b = 2;
	c = 0;
	
	c = (a > 1) || (++b >= 3);
	printf("a = %d, b = %d, and c = %d\n", a, b, c);
	
	// NOTE: do not write statements like this, this is a bad example
	
	return 0;
}*/


//-------------------------------- example 10 ----------------------------------
// this example is similar to example 9 but with no side effect order
/*#include <stdio.h>

int main(void)
{
	int a = 1;
	int b = 2;
	int c = 0;
	
	//c = (a >= 1) || (++b >= 3); // this is the same as example 9
	// NOTE: an example with side effect order, do not write like this
	
	++b;
	c = (a >= 1) || (b >= 3);
	printf("a = %d, b = %d, and c = %d\n", a, b, c);	
	// NOTE: if your intention is to always increment b then take
	//       that out of the assignment to avoid "side effect order"
	
	a = 1;
	b = 2;
	c = 0;
	
	//c = (a > 1) || (++b >= 3); // this is the same as example 9
	// NOTE: an example with side effect order, do not write like this
	
	++b;
	c = (a > 1) || (b >= 3);
	printf("a = %d, b = %d, and c = %d\n", a, b, c);
	// NOTE: if your intention is to always increment b then take
	//       that out of the assignment to avoid "side effect order"
	
	return 0;
}*/


//-------------------------------- example 11 ----------------------------------
/*#include <stdio.h>

int main(void)
{
	int b = 0;
	b = 20, b = b + 30, printf("%d\n\n\n", b);
	// NOTE: comma is left associative
	
	int a = 0;
	for(a = 1, b = 2; b < 10; a++, b++)
	{
		printf("%d %d\n", a, b);
	}
	// NOTE: you have two initialisations and two updates in this for loop
	
	return 0;
}*/


//-------------------------------- example 12 ----------------------------------
/*#include <stdio.h>

int total = 10; 
// avoid using global variables, this is for example purpose only

void myFunction(void);

int main(void)
{	
	printf("%d\n", total);
	
	myFunction();
	
	printf("%d\n", total);
	
	return 0;
}

void myFunction(void)
{
	int total = 20; // with and without int 
	printf("%d\n", total);
}*/


//-------------------------------- example 13 ----------------------------------
/*#include <stdio.h>

int main(void)
{	
	int n = 4;
	int s[4] = {-1, 0, 1, 2};
	int i = 0;
	
	if(n > 0)
		for(i = 0; i < n; i++)
			if(s[i] > 0)
				printf("non zero positive\n");
	else
		printf("no data\n");
	
	// NOTE: else statement here is matched to the nearest if, which
	//       in this example isn't what you want
		
	
	return 0;
}*/


//-------------------------------- example 14 ----------------------------------
// same as example 13, but braces are added to ensure correctness
/*#include <stdio.h>

int main(void)
{	
	int n = 4;
	int s[4] = {-1, 0, 1, 2};
	int i = 0;
	
	if(n > 0)
	{
		for(i = 0; i < n; i++)
		{
			if(s[i] > 0)
			{
				printf("non zero positive\n");
			}
		}
	}
	else
	{
		printf("no data\n");
	}
	
	// NOTE: a correctly braced program produce the correct result
		
	
	return 0;
}*/
