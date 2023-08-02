// C program for array implementation of queue 
#include <stdio.h> 
#include <stdlib.h> 
#include <limits.h> 
  
// A structure to represent a queue 
struct Queue 
{ 
    int front, rear, size; 
    unsigned capacity; 
    int* array; 
}; 
  
// function to create a queue of given capacity.  
// It initializes size of queue as 0 
struct Queue* createQueue(unsigned capacity) 
{ 
    struct Queue* queue = (struct Queue*) malloc(sizeof(struct Queue)); 
    queue->capacity = capacity; 
    queue->front = queue->size = 0;  
    queue->rear = capacity - 1;  // This is important, see the enqueue 
    queue->array = (int*) malloc(queue->capacity * sizeof(int)); 
    return queue; 
} 
  
// Queue is full when size becomes equal to the capacity  
int isFull(struct Queue* queue) 
{  return (queue->size == queue->capacity);  } 
  
// Queue is empty when size is 0 
int isEmpty(struct Queue* queue) 
{  return (queue->size == 0); } 
  
// Function to add an item to the queue.   
// It changes rear and size 
void enqueue(struct Queue* queue, int item) 
{ 
    if (isFull(queue)) 
        return; 
    // if we have nothing in the queue, then rear = capacity - 1
    // thus (queue->rear + 1)%(queue->capacity) = 0, which is the place for the first element
    // here we use mod operation to create circles in queue operaton
    queue->rear = (queue->rear + 1)%(queue->capacity); 
    queue->array[queue->rear] = item; 

    // the size should change both in enqueues and dequeues
    queue->size = queue->size + 1; 
    printf("%d enqueued to queue\n", item); 
} 
  
// Function to remove an item from queue.  
// It changes front and size 
int dequeue(struct Queue* queue) 
{ 
    if (isEmpty(queue)) 
        return INT_MIN; 

    // if we have not remove item from the queue, then front = 0, item = array[0]
    // queue->front = 1
    // here we use mod operation to create circles in queue operaton
    int item = queue->array[queue->front]; 
    queue->front = (queue->front + 1)%queue->capacity; 

    // the size should change both in enqueues and dequeues
    queue->size = queue->size - 1; 
    return item; 
} 
  
void printQueue(struct Queue* queue)
{
    if (isEmpty(queue))
    {
        printf("Queue is empty");
        return;
    }
    else
    {  
        int i;
        for(i=queue->front;(i%queue->capacity)!=queue->rear;i++)
        {
            printf("%d ", queue->array[i]);
        }
        printf("%d ", queue->array[i]);
    }
}

  
// Driver program to test above functions./ 
int main() 
{ 
    struct Queue* queue = createQueue(1000); 
    int query;

    printf("1. Enqueue\n");
    printf("2. Dequeue\n");
    printf("3. Print\n");
    printf("4. Exit\n");

    do
    {
        printf("Enter your choice: ");
        scanf("%d",&query);
        if(query==1)
        {
            int data;
            printf("Enter a number: ");
            scanf("%d",&data);
            enqueue(queue,data);
        }
        else if(query==2)
        {
            int p = dequeue(queue);
            if(p == INT_MIN)
                printf("Queue is empty\n");
            else
                printf("%d Dequeued from queue\n", p); 
        }
        else if(query==3)
        {
            printf("The queue is: ");
            printQueue(queue);
            printf("\n");
        }
        else if(query==4)
        {
            return 0;
        }
        else
        {
            printf("Invalid input.\n");
        }
    }while(1);
  
    return 0;
}
