#include <stdio.h>

// Passing 2D array: a dimension is available globally
const int M = 3;
const int N = 3;

void print(int arr[M][N]);

int main(void)
{
    int arr[][3] = {{1,2,3},{4,5,6},{7,8,9}};
    print(arr);

    return 0;
}


void print(int arr[M][N])
{
    int i, j;
    for (i=0; i<M; i++){
        for (j=0; j<N; j++){
            printf("%d", arr[i][j]);
        }
    }

}