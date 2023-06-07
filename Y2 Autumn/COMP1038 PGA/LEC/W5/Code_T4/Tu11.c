#include <stdio.h>

void sel_sort(int arr[], int n);

int delete(int arr[], int n);

int main(void)  // lab4 detele.c
{
    int i, n;
    printf("please enter the numbers: ");
    scanf("%d", &n);

    // input
    int arr[n];
    printf("Please enter your array: ");
    for (i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }

    // testing 1
    printf("Before sorting: ");
    for (i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");

    sel_sort(arr, n);

    // testing 2
    printf("After sorting:  ");
    for (i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");

    n = delete(arr, n);

    // testing 3
    printf("After deleting:  ");
    for (i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

void sel_sort(int arr[], int n)
{
    int i, j, temp, t;
    for (i=0; i<n; i++){
        temp = i;
        for (j=i+1; j<n; j++){
            if (arr[j] < arr[temp]){
                temp = j;
            }
        }
        t = arr[temp];
        arr[temp] = arr[i];
        arr[i] = t;
    }
}

int delete(int arr[], int n)
{
    int i, j, k;

    for (i=0; i<n; i++){
        for (j=i+1; j<n; j++){
            while ((arr[j] == arr[i])&&(n>=i+2)){
                for (k=j;k<=n-2;k++){
                    arr[k] = arr[k+1];
                }
                n--;
            }
        }

        // test printing whenever i changes
        printf("i = %d, n = %d, array3: ", i, n);
        for (k=0;k<n;k++){
            printf("%d ", arr[k]);
        }
        printf("\n");
    }
    return n;
}