#include<stdio.h> 

int main(void){

    int std[4]; int i;

    std[0] = 100; //valid

    std[1] = 200; //valid

    std[2] = 300; //valid

    std[3] = 400; //valid

    std[4] = 500; //invalid(out of bounds index) //printing all elements

    for( i=0; i<5; i++ ){
        printf("std[%d]: %d\n",i,std[i]); 
    }

    return 0;

}