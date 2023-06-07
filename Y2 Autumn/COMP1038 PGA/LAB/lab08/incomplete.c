#include <stdio.h>
#include <stdlib.h>

/* Definition of the structure. */
struct int_list {
   int value;
   struct int_list *next;
};
typedef struct int_list IntList;

/** Return the length of the list.
** TODO test!
*/
int list_length(IntList *start)
{
   if(start == NULL)
   {
      return 0;
   }
   
   int total = 1;
   IntList *cur = start;
   while(cur->next != NULL)
   {
      cur = cur->next;
      total++;
   }
   return total;
}

/* Print the contents of the list.
** TODO test, correct output format!
*/
void list_print(IntList *start)
{
   IntList *cur = start;
   while(cur != NULL)
   {
      printf("%d\n", cur->value);
      cur = cur->next;
   }
}

/* Append a new value to the end of the list.
** TODO finish, test!.
*/
void list_append(IntList **start, int newval)
{
   IntList *newel = malloc(sizeof(IntList));
   if(newel == NULL)
   {
      /// error?
   }
   newel->value = newval;
   newel->next = NULL;
   
   if(*start == NULL)
   {
      *start = newel;
   }
   else
   {
      IntList *cur = *start;
      while(cur->next != NULL)
      {
	 cur = cur->next;
      }
      cur->next = newel;
   }
     
}

/* Use the main function for testing your other functions. */
int main(int argc, char *argv[])
{
   IntList *start = NULL;
   list_append(&start, 42);
   list_print(start);		/* Expect to see just 42. */
}