#include <stdio.h>

int main(void)  // 写出自己的strlen函数
{
    // Method 1: We can declare our string as an array of characters
    // Method 2: We can also declare it our string as char *
    char name[] = {'P','a','u','l','\0'};   // 如果没有'\0'也可以运行成功
    char *str = name;                   // "name" is equivalent to "&name[0]"

    // Method 1: use array notation
    int n = 0;
    while (name[n] != '\0'){
        printf("%c", name[n]);          // 在此处把数组名称换成str依旧可以运行成功
        n = n + 1;
    }
    printf("\nArray notation length: %d.\n\n", n);

    // Method 2: use pointer arithmetic
    int len = 0;
    while (*str != '\0'){
        printf("%c", *str);
        str = str + 1;  // 指向下一个字符
        len = len + 1;
    }
    printf("\nPointer arithmetic length: %d.\n", len);

    return 0;
}
