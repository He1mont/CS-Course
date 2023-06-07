#include <stdio.h>

int main(void){  // delete the duplicate elements in array3

    int i, j, k;
    int cnt = 10;
    int arr3[10] = {0,0,1,1,2,2,3,3,3,3};  // 0,1,2,3,,5

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