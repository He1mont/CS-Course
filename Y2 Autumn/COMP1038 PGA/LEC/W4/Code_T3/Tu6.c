#include <stdio.h> 

int main(int argc, char* argv[]) 
{ 
    int a;

    a = 100;

    printf("%d", a);

    int *ptr = NULL;

    *ptr=100;

    printf("%d, %p", *ptr, ptr);

}