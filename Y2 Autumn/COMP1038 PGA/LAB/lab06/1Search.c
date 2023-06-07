#include <stdio.h>

void iter(int n, int lent, int arr[]);
int recur(int start, int end, int n, int arr[]);

int main(void)
{
    int arr[10] = {1,2,3,4,8,6,7,8,9,10};
    int len = sizeof(arr)/sizeof(arr[0]);

    iter(8,len,arr);

    int pos = recur(0, len-1, 4, arr);
    printf("the value %d is in the postion %d.\n",4, pos);
    return 0;
}

void iter(int n, int len, int arr[])
{
    int i;
    for (i=0;i<len;i++){
        if (arr[i] == n){
            printf("the value %d is in the position %d.\n",n, i+1);
        }
    }

}

int recur(int start, int end, int n, int arr[])
{
    if (start == end){
        return -1;
    } else if(arr[start] == n) {
        return start + 1;
    } else {
        return recur(start+1, end, n, arr);
    }
}