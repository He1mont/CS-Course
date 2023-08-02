#include <stdio.h>
#include <string.h>

int main(void)  // String Literals
{
    // printf("%c %c\n", "message"[4], *("message"+4));  // ???

    // String literals is usually read-only
    char *ptr = "This is Text";         // 可以将ptr理解为一个数组？
    
    printf("%c %c\n", ptr[5],*(ptr+5)); // i i
    printf("%s\n", ptr);                // This is Text
    printf("%s\n", ptr+5);              // is Text

    printf("\n");

    int len = strlen(ptr);

    // 字符串储存在数组ptr[]里？
    int i;
    for (i=0;i<len;i++){
        printf("\"%c\" ", ptr[i]);
    }

    return 0;
}
