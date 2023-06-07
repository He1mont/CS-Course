#include <stdio.h>

void swap(int** arg1, int** arg2)
{
    int *value;     // int value为一级指针
    value = *arg1;  // arg1是二级指针，所以*arg1是一级指针，和value平级
    *arg1 = *arg2;
    *arg2 = value;
    printf("in the SWAP we have:\t%p, %p\n", &arg1, &arg2);
}

int main(void)
{
    int a = 1, b = 2;
    printf("before SWAP we have:\t%p, %p\n", &a, &b);

    int *pa = &a, *pb = &b;
    int **ppa = &pa, **ppb = &pb;   // **是二级指针的定义

    swap(ppa, ppb);

    printf("after SWAP we have:\t%p, %p\n", &a, &b);    // 交换不成
    printf("after SWAP we have:\t%p, %p\n", pa, pb);    // 能交换成

/* a和b的地址在定义的时候就已经在内存里被决定了
 * 这是物理上的事实，因此a和b的地址不能交换
 * 对于这道题，我们先让pa和pb指向a和b，因此pa和pb存的是a和b的地址，
 * 再让ppa和ppb指向pa和pb
 * 
 * 在函数里，我们交换的都是copy的值，对于a和b本身的值来说没有影响
 * 因此我们定义二级指针，通过pass by reference的方法来交换a和b的地址，即pa和pb的值
 */ 
    return 0;
}