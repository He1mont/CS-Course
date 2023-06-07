#include <stdio.h>

int main() 
{  
   FILE *fp;
   char buff[255];
   fp = fopen("./tmp/test.txt", "w");
   
   if(fp == NULL)
   {
      printf("Error, file opening failed\n");
      return 1;
   }
   fgets(buff,255,stdin);
   fprintf(fp, buff);
   fclose(fp);

   return 0;
}
