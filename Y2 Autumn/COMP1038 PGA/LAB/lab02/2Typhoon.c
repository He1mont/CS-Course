// 判断台风等级
#include <stdio.h>

int main(void)
{
    int speed;

    printf("the wind speed is: ");
    scanf("%d", &speed);

    if (speed < 0){
        printf("Impossible wind speed");
    } else if (speed <= 62){
        printf("It is Tropical Depression");
    } else if (speed <= 118){
        printf("It is Typhoon");
    } else if (speed <= 156){
        printf("It is Strong Typhoon");
    } else if (speed <= 192){
        printf("It is Very Strong Typhoon");
    } else {
        printf("It is Violent Typhoon");
    }

    return 0;
}