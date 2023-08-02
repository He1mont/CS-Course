#include <stdio.h>

void test(void); 

int main(void)
{
    test(); // 101, 1
    test(); // 102, 1
    
    return 0; 
} 

void test()
{ 
    static int i = 100; 
    int j = 0; 

    i++; 
    j++; 
    printf("%d %d\n", i, j); 

}

