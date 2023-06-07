#include <stdio.h>

int main(void)  // array of pointers
{
    // define a array of pointers
    const char *suit[4] = {"Spades","Hearts","Clubs","Diamonds"};

    printf("print out the strings: \n");
    int i;
    for (i=0;i<4;i++){
        printf("%s\n", suit[i]);
    }

    printf("\nprint each character of a string using pointers: \n");
    for (i=0;i<4;i++){
        while (*suit[i]!='\0'){
            printf("%c ", *suit[i]);
            *suit[i]++;     // 通过指针的移动来遍历字符串中的每一个字符
        }                   // 但是为什么会有warning？
        printf("\n");
    }

    // suit[]是array of pointers，suit[0]是指针
    // 因此无法做到以下像二维数组的输出
    // printf("%c\n", suit[0][0]);
    // printf("%c\n", suit[0][1]);
    // printf("%c\n", suit[0][2]);

    // 下面是用二维数组的方式来完成array of pointers的操作
    printf("\n\nAnother way of doing it by dimensional array:\n");
    const char *arr[4]; // 如果是const char arr[4]则无法运行
    arr[0] = "Spades";
    arr[1] = "Hearts";
    arr[2] = "Clubs";
    arr[3] = "Diamonds";

    int j = 0;
    for (i=0;i<4;i++){
        while (arr[i][j]!='\0'){
            printf("%c", arr[i][j]);
            j++;
        }
        j = 0;
        printf("\n");
    }

    // printf("%c\n", arr[0][0]);
    // printf("%c\n", arr[0][1]);
    // printf("%c\n", arr[0][2]);

    return 0;
}