// Enforcing Privacy with Cryptography
#include <stdio.h>
#include <math.h>

int main(void)
{
    const int size = 4;
    int a[size] = {0};

    int input = 0;
    printf("please type a encrpted number of 4 digits: ");
    scanf("%d", &input);

    // get every digit
    int i = 0;
    while (input!=0){
       a[i] = input%10;
       input = input / 10;
       i++; 
    }

    // check
    for (i=0; i<4; i++){
        printf("%d ", a[i]);
    }
    printf("\n");

    // swap the 1st and 3rd, the 2nd and 4th
    int t = 0;
    t = a[1];
    a[1] = a[3];
    a[3] = t;

    t = a[0];
    a[0] = a[2];
    a[2] = t;

    // check
    for (i=0; i<4; i++){
        printf("%d ", a[i]);
    }
    printf("\n");

    // decrption and calculate output
    int output = 0;
    for (i=0; i<4; i++){
        if (a[i]>7){
            a[i] = a[i] - 7;
        } else {
            a[i] = a[i] + 3;
        }
        output = output + a[i]*pow(10,i);
    }

    printf("The decrpted number is: %d", output);

    return 0;
}