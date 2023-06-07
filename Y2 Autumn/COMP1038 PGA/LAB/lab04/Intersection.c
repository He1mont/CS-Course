#include <stdio.h>

int main(void)
{
    int arr1[10], arr2[10], arr3[10];
    int i, j, k;

    // initilization of array 1 and 2
    printf("please type in array 1: ");
    for (i=0; i<10; i++){
        scanf("%d", &arr1[i]);
    }

    printf("please type in array 2: ");
    for (i=0; i<10; i++){
        scanf("%d", &arr2[i]);
    }

    // count the intersection and store them in array3
    int cnt = 0;
    for (i=0; i<10; i++){
        for (j=0;j<10;j++){
            if (arr1[i] == arr2[j]){
                arr3[cnt] = arr2[j];
                cnt++;
            }
        }
    }

    // test printing
    printf("The intersection is: ");
    for (i=0; i<cnt; i++){
        printf("%d ", arr3[i]);
    }
    printf(", and cnt = %d.\n\n", cnt);
    
    // delete the duplication of arr3
    for (i=0; i<cnt; i++){
        for (j=i+1; j<cnt; j++){
            while ((arr3[j] == arr3[i])&&(cnt>=i+2)){
                for (k=j;k<=cnt-2;k++){
                    arr3[k] = arr3[k+1];
                }
                cnt--;
            }
        }
        // test printing whenever i changes
        printf("i = %d, cnt = %d, array3: ", i, cnt);
        for (k=0;k<cnt;k++){
            printf("%d ", arr3[k]);
        }
        printf("\n");
    }

    // print out
    printf("\ncnt = %d\n", cnt);
    printf("The final print: ");
    for (i=0; i<cnt; i++){
        printf("%d ", arr3[i]);
    }

    return 0;
}