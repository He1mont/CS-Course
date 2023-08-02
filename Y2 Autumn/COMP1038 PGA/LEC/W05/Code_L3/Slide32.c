#include <stdio.h>

void testArray(int *a, int size);   // pass by reference

int main(void)
{
    int array[3] = {1,2,3};

    printf("Output from main()\n");
    int i = 0;
    for (i=0; i<3; i++){
        printf("%d %d\n", i, array[i]);
    }
    printf("\n\n");

    testArray(array, 3);

    printf("Output from main()\n");
    for (i=0; i<3; i++){
        printf("%d %d\n", i, array[i]);
    }

    return 0;
}

void testArray(int *a, int size)
{
    printf("Output from testArray()\n");

    int i = 0;
    for (i=0; i<size; i++){
        printf("%d %d\n", i, a[i]);
    }
    printf("\n\n");

    a[0] = 333;

    printf("Output from testArray() after changing the value of a[0]\n");
    for (i=0; i<size; i++){
        printf("%d %d\n", i, a[i]);
    }
    printf("\n\n");
}