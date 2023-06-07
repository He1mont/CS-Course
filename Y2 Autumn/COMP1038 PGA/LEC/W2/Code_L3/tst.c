#include <stdio.h>

int main(void)
{
    printf("%d\t", 5/2);
    printf("%.2f\t", 5.0/2);
    printf("%.2f", 5/2.0);
    
    // 输出分别为2，2.5，2.5
    
    return 0;
}