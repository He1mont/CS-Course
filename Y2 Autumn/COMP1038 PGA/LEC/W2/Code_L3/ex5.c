#include <stdio.h>

int main(void)
{
    int day = 0;
    int month = 0;
    int year = 0;
    int count = 0;

    printf("Please enter your date of birth (dd/mm/yy): ");
    count = scanf("%d/%d/%d", &day, &month, &year); 
    // 这里count用来计算输入了几个数据
    // 输入必须严格按照scanf括号里的形式

    printf("There are %d correctly formatted values\n", count);
    printf("The values are %d, %d and %d\n", day, month, year);

    return 0;
}