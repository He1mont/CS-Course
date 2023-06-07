// Printing the Decimal Equivalent of a Binary Number
#include <stdio.h>
#include <math.h>

int main(void)
{
    int bi = 0;
    int de = 0;
    printf("please type a binary number fewer than 6 digits: ");
    scanf("%d", &bi);

    const int size = 8;
    int bin[size] = {0};
    int dec[size] = {0};

    // store the binary number by array
    int i = 0;
    while (bi != 0){
        bin[i] = bi % 10;
        bi = bi / 10;
        i++;
    }

    // calculate the decimal number
    for (i=0; i<size; i++){
        if (bin[i]==1){
            de += pow(2,i);
        }
    }

    printf("%d\n", de);

    return 0;
}