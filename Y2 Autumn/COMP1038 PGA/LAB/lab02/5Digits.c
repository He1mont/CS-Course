// seperate a number into digits
#include <stdio.h>

int main(void)
{
    int num;
    printf("please enter a number:");
    scanf("%d", &num);

    if (num < 0){
        printf("Inproper Input!");
    }

    int num0 = num;
    int len = 0;
    while (num0 > 0){
        num0 = num0 / 10;
        len = len + 1;
    }

    int a[len];
    int i;
    for (i=0; i<len; i++){
        a[i]= num % 10;
        num = num / 10;
    }

    for (i=0; i<len; i++){
        printf("%d\t", a[i]);
    }

    return 0;
}