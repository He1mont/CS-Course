#include<stdio.h>
#include<stdlib.h>

void print1(void); //prototype
void print2(void);

int main(void)
{
   atexit(print1); //register function print
   atexit(print2);
   puts("Enter 1 to terminate program with function exit\nEnter 2 to terminate program normally");
   int answer;
   scanf("%d", &answer);

   if (answer == 1){
      puts("\n Terminating program with function exit");
      exit(EXIT_SUCCESS);
   }
   puts("\nTerminating program by reaching the end of main");

}

void print1 (void)
{
   puts("In print1: Executing function print at program termination\nProgram terminated");
}

void print2 (void)
{
   puts("In print2: Executing function print at program termination\nProgram terminated");
}