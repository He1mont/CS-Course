#include <stdio.h>

int main(void)
{
    int num;
    printf("Please enter the amount of numbers: ");
    scanf("%d", &num);

    int i, j, temp, t, k;
    int arr[num];
    printf("Please enter each element of the array: ");
    for (i=0;i<num;i++){
        scanf("%d", &arr[i]);
    }

    // // selection sort
    // for (i=0; i<num; i++){
    //     temp = i;
    //     for (j=i+1; j<num; j++){
    //         if (arr[j]<arr[temp]){
    //             temp = j;           // note the location of the smallest number
    //         }
    //     }
    //     t = arr[temp];
    //     arr[temp] = arr[i];
    //     arr[i] = t;
    // }

    // // print out
    // printf("Here are the sorted numbers: \n");
    // for (i=0;i<num;i++){
    //     printf("%d", arr[i]);
    // }

    // bubble sort
    for (i=0; i<num; i++){          // i代表第几遍遍历 
        for (j=0; j<num-1-i; j++){
            if (arr[j] > arr[j+1]){
                t = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = t;
            }
        }
        for (k=0;k<num;k++){
            printf("%d", arr[k]);
        }
        printf("\n");
    }

    // print out
    printf("\nHere are the sorted numbers: \n");
    for (i=0;i<num;i++){
        printf("%d", arr[i]);
    }



    return 0;
}