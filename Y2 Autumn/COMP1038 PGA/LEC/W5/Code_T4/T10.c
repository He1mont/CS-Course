#include <stdio.h>

void func(int arr[])
{
    int len = sizeof(arr)/sizeof(int);

    printf("in function, we have: \n");
    printf("len = %d\n", len);      // 这里的len没有任何意义
    printf("size of arr = %lu\n", sizeof(arr));
                                    // 这里的sizeof(arr)表示arr的地址的长度
                                    // 也表示指针的长度
}

int main(void)
{
    int arr[35];                    // 这里的sizeof(arr)表示数组在内存中占的长度
    int len = sizeof(arr)/sizeof(int);

    printf("len = %d\n", len);      // 这里的len表示数组的长度
    printf("size of arr = %lu\n\n", sizeof(arr));

    func(arr);

    return 0;
}