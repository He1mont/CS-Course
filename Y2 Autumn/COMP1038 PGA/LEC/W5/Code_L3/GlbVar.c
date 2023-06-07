#include <stdio.h>

int glb = 100;
int f(int n);

int main(void)
{
    printf("1: in main, \t\tglb = %d\n", glb);
    glb = f(glb);
    printf("4: after function, \tglb = %d\n", glb);

    return 0;
}

int f(int n)
{
    int glb = 10;
    printf("2: in function, \tglb = %d\n", glb);
    {
        int glb = 0;
        printf("3: in the block, \tglb = %d\n", glb);
    }
    return glb;

}

