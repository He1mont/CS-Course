#include <stdio.h>

int main(void)
{
    int id = 0;

    printf("Current ID number is %d\n", id);
    printf("Current ID number is %p\n", &id);   // &id是计算机中储存id的地址

    printf("\n\nEnter your ID number:");
    scanf("%d", &id);

    printf("\n\nCurrent ID number is %d\n", id);
    printf("Current ID number is %p\n", &id);

    return 0;
}