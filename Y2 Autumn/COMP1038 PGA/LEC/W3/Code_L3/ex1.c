//-------------------------------- example 1 ----------------------------------
// Also used in iteration.c

#include <stdio.h>

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
}