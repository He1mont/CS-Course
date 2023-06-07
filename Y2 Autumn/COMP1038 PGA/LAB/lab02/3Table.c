// 输出1-10的平方和立方
#include <stdio.h>
#include <math.h>

int main(void)
{
    printf("%s\t%s\t%s\t\n", "number", "square", "cube");

    int i;
    for (i=0; i<=10; i++){
        printf("%d\t%d\t%d\t\n", i, i*i, i*i*i);
    }

    return 0;
}