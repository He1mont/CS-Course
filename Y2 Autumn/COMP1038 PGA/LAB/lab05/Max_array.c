#include <stdio.h>

int max(int len, int arr[len]);

int main(void)      // 找出一个数组中最大的数
{
    int i, len;
    printf("please enter the numbers: ");
    scanf("%d", &len);

    // input
    int arr[len];
    printf("Please enter your array: ");
    for (i=0; i<len; i++){
        scanf("%d", &arr[i]);
    }

    printf("The Max element in the array is %d\n", max(arr,len));

    return 0;
}

int max(int len, int arr[len])
{
    int i, temp = 0;
    for (i=1; i<len; i++){
        if (arr[i] > arr[temp]){
            temp = i;
        }
    }
    return arr[temp];
}