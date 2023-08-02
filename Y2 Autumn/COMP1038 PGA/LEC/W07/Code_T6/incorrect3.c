#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student {     // general initialization
   int id;
   char name[25];
   float avg_mark;
};

// Print the details for a student.
void print_student(struct student s)
{
   printf("id = %d\n", s.id);
   printf("name = %s\n", s.name);
   printf("avg_mark = %f\n", s.avg_mark);
}

// Return true if two students are equal.
int equal_students(struct student a, struct student b)
{
   if(a.id != b.id)
      return 0;
   if(a.avg_mark != b.avg_mark)
      return 0;
   if(strcmp(a.name, b.name) != 0)
      return 0;
   return 1;
}

// Free any allocated resources for the given student.
void free_student(struct student s)
{
   free(s.name);
}

int main(int argc, char *argv[])
{
   struct student me;
   me.id = 12345;
   printf("Enter the name of first student: ");
   scanf("%s", me.name );
   me.avg_mark = 88;

   struct student you;
   you.id = 12345;
   printf("Enter the name of second student: ");
   scanf("%s", you.name );
   you.avg_mark = 88;

   if(equal_students(me, you))
      printf("Same\n");
   else
      printf("Diff\n");

   // free_student(me);
   // free_student(you);
   
}