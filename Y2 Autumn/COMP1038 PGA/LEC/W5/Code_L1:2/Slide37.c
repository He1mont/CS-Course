#include <stdio.h> 

void swap(int *, int *); //prototype of the function 

int main(void){

    int a = 10;
    int b = 20;

    printf("Before swapping the values in main a = %d, b = %d\n",a,b); 

    swap(&a,&b); 
    printf("After swapping values in main a = %d, b = %d\n",a,b);

} 

void swap (int *a, int *b) { 
    
    int temp;
    temp = *a;

    *a=*b; 
    *b=temp; 
    printf("After swapping values in function a = %d, b = %d\n",*a,*b);

}