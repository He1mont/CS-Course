#include <stdio.h>

void func(int* arg1, int* arg2)     // pass by references
{
    int value;
    value = *arg1;  // 交换指针所指的对象的值
    *arg1 = *arg2;
    *arg2 = value;
}

int main(void)
{
    int a = 1;
    int b = 2;
    func(&a, &b);   // 上传的是a和b的地址，这样的话就可以用指针arg1和arg2指向a和b
    printf("%d, %d\n", a, b);       // 2, 1

    return 0;
}