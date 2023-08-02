#include <stdio.h>

#define SIZE 10

int main(void)	// 数组的初始定义
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
}