#include <stdio.h>
 
void sort_array_ascending(float arr[], int length);
void sort_array_descending(float* arr, int length);
 
int main()
{
    int num, i;
 
    printf("Enter number of elements: ");
    scanf("%d", &num);
    float heap[num]; 
    printf("Enter the elements: ");
    for (i = 0; i < num; i++)
       scanf("%d", &heap[i]);

    printf("\nThe sorted array are:\n");
    printf("Ascending order: ");
    sort_array_ascending(heap, num);
    for (i = 0; i < num; i++)
       printf("%f ", heap[i]);

    printf("\nDescending order: ");
    sort_array_descending(heap, num);
    for (i = 0; i < num; i++)
       printf("%f ", heap[i]);
    printf("\n");
            
    return 0;
}

void sort_array_ascending(float arr[], int length)
{
	int i=0, j=0, min_idx;
 
    // One by one move boundary of unsorted subarray
    do
    {
         // Find the minimum element in unsorted array
        min_idx = i;
        j = i+1;
        do
        {
            if (arr[j] < arr[min_idx])
                min_idx = j;
            j++;
            
 		}while(j<length);
        // Swap the found minimum element
        // with the first element
        float temp = arr[min_idx];
    	arr[min_idx] = arr[i];
    	arr[i] = temp;
       	i++;
    }while(i < length); 
}

void sort_array_descending(float* arr, int length)
{
	int i=0, j=0, min_idx;
 
    // One by one move boundary of unsorted subarray
    do
    {
         // Find the minimum element in unsorted array
        min_idx = i;
        j = i+1;
        do
        {
            if (arr[j] > arr[min_idx])
                min_idx = j;
            j++;
            
 		}while(j<length);
        // Swap the found maximum element with the first element
        float temp = arr[min_idx];
    	arr[min_idx] = arr[i];
    	arr[i] = temp;
       	i++;
    }while(i < length); 
}