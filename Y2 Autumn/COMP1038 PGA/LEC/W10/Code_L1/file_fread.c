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
   FILE *fptr;
   
   if ((fptr = fopen("./tmp/program.bin","rb")) == NULL){
      printf("Error in opening file!\n");
      exit(1);    // Program exits if the file pointer returns NULL.
   }

   for(n = 1; n < 5; ++n){
      fread(&num, sizeof(struct threeNum), 1, fptr);
      printf("n1: %d\tn2: %d\tn3: %d\n", num.n1, num.n2, num.n3);
   }

   fclose(fptr);
   return 0;
}
