//-------------------------------- example 1 ----------------------------------
#include <stdio.h>
#include <math.h>	// remember to use -lm when compile

int main(void)		// slide 3
{
	printf("%d\n", 7 + 5 * 3 - 1);
	printf("%d\n", 7 * 4 / 2 * 5);
	
	printf("%d\n", (10 % 8));

	printf("%f\n", fmod(10.5, 8.2));	// fmod = float mod
	
	printf("%d\n", 5/3);
	
	printf("%f\n", 5/3);
	
	printf("%f\n", 4.2/2.1);
	printf("%f\n", 4.2/2);
	
	printf("%d\n", 4.2/2);
	// NOTE: float/int gives float as the output i.e. what you see in your
	//       output should be wrong
	
	return 0;
}

