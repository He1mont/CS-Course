// Sorting an array of numbers in decending order
#include <stdio.h>

int main(void)
{
    int num = 0;
    printf("Enter number of marks: ");
    scanf("%d", &num);

    // use for loop to store numbers
    int i;  int arr[num];
    for (i=0; i<num; i++){
        printf("Enter mark %d: ", i+1);
        scanf("%d", &arr[i]);
    }

    // selection sort

    int t; int j; int temp;     // 用temp标记数组中最大数的位置
    for (i=0; i<num; i++){
        temp = i;               // 假设arr[i]是最大的    
        for (j=i+1;j<num;j++){  // 这个loop用来找到最大的数在哪里
            if (arr[j] > arr[temp]){
                temp = j;
            }
        }
        // 把最大的数放到最前面
        t = arr[temp];
        arr[temp] = arr[i];
        arr[i] = t;
    }
    
    // print out
    for (i=0; i<num; i++){
        printf("%d\t", arr[i]);
    }

    return 0;
}