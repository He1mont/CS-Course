// A C program to demonstrate linked list based implementation of queue 
#include <stdio.h> 
#include <stdlib.h> 
  
// A linked list (LL) node to store a queue entry 
struct QNode { 
    int key; 
    struct QNode* next; 
}; 
  
// 2 pointers pointing to the first and last node in the queue respectively
struct Queue { 
    struct QNode *headPtr, * tailPtr; 
}; 
  
// A utility function to create a new linked list node. 
struct QNode* newNode(int k) 
{ 
    struct QNode* tempPtr = (struct QNode*)malloc(sizeof(struct QNode)); 
    tempPtr->key = k; 
    tempPtr->next = NULL; 
    return tempPtr; 
} 
  
// A utility function to create an empty queue
struct Queue* createQueue() 
{ 
    struct Queue* newPtr = (struct Queue*)malloc(sizeof(struct Queue)); 
    newPtr -> headPtr = newPtr ->tailPtr = NULL; 
    return newPtr; 
} 
  

// The function to add a key k to q 
void enqueue(struct Queue* q, int k) 
{ 
    // Create a new LL node 
    struct QNode* newPtr = newNode(k); 
  
    // If queue is empty, then new node is front and rear both 
    if (q->headPtr == NULL) { 
        q-> headPtr = q->tailPtr = newPtr; 
        printf("%d enqueued to queue\n", k);
        return; 
    } 
  
    // Add the new node at the end of queue and change rear 
    q-> tailPtr->next = newPtr; 
    q-> tailPtr = newPtr; 
    printf("%d enqueued to queue\n", k);
} 
  
// Function to remove a key from given queue q 
struct QNode* dequeue(struct Queue* q) 
{ 
    // If queue is empty, return NULL. 
    if (q->headPtr == NULL) 
        return NULL; 
  
    // Store previous front and move front one node ahead 
    struct QNode* tempPtr = q->headPtr; 
    q-> headPtr = q-> headPtr ->next; 

    // if the queue has only one element 此时tailptr在headptr的前面
    if (q-> headPtr == NULL) 
        q->tailPtr = NULL; 
    return tempPtr; 
} 

void printQueue(struct Queue* q)
{
    if (q->headPtr == NULL){
        return;

    } else {  
        struct QNode* tempPtr = q->headPtr;
        while(tempPtr != NULL){
            printf("%d ", tempPtr->key);
            tempPtr = tempPtr->next;
        }
    }
}
  
// Driver Program to test anove functions 
int main() 
{ 
    // q is a structure pointer pointing to the whole queue
    struct Queue* q = createQueue(); 
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
            enqueue(q,data);
        }
        else if(query==2)
        {
            struct QNode* n = dequeue(q); 
            if (n == NULL) {
                printf("Queue is empty\n"); 
            } else {
                printf("%d Dequeued from queue\n", n->key);
                free(n);
            }
        }
        else if(query==3)
        {
            printf("The queue is: ");
            printQueue(q);
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