// convert seconds into hour:minute:second
#include <stdio.h>

int main(void)
{
    int sec;
    printf("Enter the Seconds:");
    scanf("%d",&sec);

    int min = sec / 60;
    sec = sec % 60;

    int hour = min / 60;
    min = min % 60;

    printf("the time is %d:%d:%d", hour, min, sec);

    return 0;
}