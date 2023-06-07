#include <stdio.h>
#include <stdlib.h>
struct threeNum
{
   int n1, n2, n3;
};

int main()
{
   int n;
   struct threeNum num;
   FILE *fp;

   if ((fp = fopen("./tmp/program.bin","wb")) == NULL) {  
      printf("Error in file opening\n");
      exit(1);    // Program exits if the file pointer returns NULL.
   }

   for(n = 1; n < 5; ++n){
      num.n1 = n;
      num.n2 = 5*n;
      num.n3 = 5*n + 1;
      fwrite(&num, sizeof(struct threeNum), 1, fp);
   }
   
   fclose(fp);
   return 0;
}
