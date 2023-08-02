#include <stdio.h>

int main(void)
{
    char *ptr = "1234567890asdfgh";

    // Case 1：正常运行
    // int i;
    // for (i=0;i<17;i++){
    //     printf("the result is: %c\n", *ptr);
    //     *ptr++;
    // }

    // Case 2：和Case 1运行结果一样
    printf("\n\nthe result is: %c\n", *(ptr+7));  
    printf("the result is: %c\n", *(ptr+8));  
    printf("the result is: %c\n", *(ptr+9));  
    printf("the result is: %c\n", *(ptr+10));  
    printf("the result is: %c\n", *(ptr+11));  
    printf("the result is: %c\n", *(ptr+12));  

    // *ptr += 5; default: *ptr = *(ptr+5)

    // // Case 3：会按照ASCII码表的顺序输出
    // printf("\n\nthe result is: %c\n", *ptr+8);
    // printf("the result is: %c\n", *ptr+9);
    // printf("the result is: %c\n", *ptr+10);
    // printf("the result is: %c\n", *ptr+11);
    // printf("the result is: %c\n", *ptr+12);
    // printf("the result is: %c\n", *ptr+13);

    return 0;
}