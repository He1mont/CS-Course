// C program for linked list implementation of stack 
#include <limits.h> 
#include <stdio.h> 
#include <stdlib.h> 
  
// A structure to represent a stack 
struct StackNode { 
    int data; 
    struct StackNode* next; 
}; 

struct StackNode* newNode(int data) 
{ 
    struct StackNode* stackNode = (struct StackNode*)malloc(sizeof(struct StackNode)); 
    stackNode->data = data;
    stackNode->next = NULL; 
    return stackNode; 
} 
  
int isEmpty(struct StackNode* topPtr) 
{ 
    return !topPtr; 
} 
  
void push(struct StackNode** topPtr, int data) 
{ 
    // allocate node
    struct StackNode* newPtr = newNode(data); 
    // insert at beginning
    newPtr->next = *topPtr; 
    *topPtr = newPtr; 
    printf("%d pushed to stack\n", data); 
} 
  
int pop(struct StackNode** topPtr) 
{ 
    if (isEmpty(*topPtr)) 
        return INT_MIN; 
    // allocate node
    struct StackNode* tempPtr = *topPtr; 
    // delete the first node
    *topPtr = (*topPtr)->next; 
    int popped = tempPtr->data; 
    free(tempPtr); 
  
    return popped; 
} 

void printStack(struct StackNode** topPtr)
{
    if (isEmpty(*topPtr))
    {
        printf("Stack is empty");
        return;
    }
    else
    {   
        struct StackNode* tempPtr = *topPtr; 
        while (tempPtr!=NULL)
        {
            printf("%d ", tempPtr->data);
            tempPtr = tempPtr->next;
        }
    }
}
  
int main() 
{ 
    struct StackNode* topPtr = NULL; 
    
    int query;
    printf("1. Push\n");
    printf("2. Pop\n");
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
            push(&topPtr,data);
        }
        else if(query==2)
        {
            int p = pop(&topPtr);
            if(p == INT_MIN)
                printf("Stack is empty\n");
            else
                printf("%d popped from stack\n", p); 
        }
        else if(query==3)
        {
            printf("The stack is: ");
            printStack(&topPtr);
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