#include <stdio.h>
#include <stdlib.h>
#include <limits.h> 

typedef struct Node{
    int data;
    struct Node *next;
}node;

void push(node** head, int data);
int pop(node** head);
void display(struct Node* head);
void freenode(node** head);

int main(int argc, char* argv[])
{
    struct Node *head = NULL;
    int opt;
    int data;
    int p;

    printf("1. Push\n");
    printf("2. Pop\n");
    printf("3. Print\n");
    printf("4. Exit\n");

    do{
        printf("Enter your choice: ");
        scanf("%d", &opt);
        
        if (opt == 1){
            printf("Please enter your data: ");
            scanf("%d", &data);
            push(&head, data);

        } else if (opt == 2){
            if (p == INT_MIN) {
                printf("The stack is empty!\n");
            } else {
                p = pop(&head);
                printf("The popped value is: %d\n", p);
            }

        } else if (opt == 3){
            display(head);

        } else if (opt == 4){
            freenode(&head);
            exit(0);

        } else{
            printf("Invalid input!\n");
        }
        
    } while(1);


    return 0;
}

void push(node** head, int data)
{
    // allocate node
    node* tmp = *head;
    node* newnode = (node*)malloc(sizeof(node));
    
    // put into data
    newnode->data = data;
    newnode->next = NULL;

    if (!*head){
        *head = newnode;
        return;
    }
    while (tmp!=NULL){
        tmp = tmp->next;
    }
    tmp = newnode;    // link the node to the list
    return;
}

int pop(node** head)
{   
    if (!*head){
        return INT_MIN;
    }
    // allocate node
    node* tmp = *head;

    // if the stack has only one node
    if (!tmp->next){
        *head = NULL;
        return tmp->data;
    }

    while ((tmp->next)->next != NULL){
        tmp->next = NULL;
    }
    return tmp->data;

}

void display(struct Node* head)
{
    if (!head){
        printf("The stack is empty!\n");
        return;
    }
    printf("The stack is: ");
    while (!head){
        printf("%d ", head->data);
        head = head->next;
    }
    return;
}

void freenode(node** head)
{
    if (*head == NULL){
        return;
    }

    node* tmp = *head;
    while (tmp!= NULL){
        free(tmp);
        tmp = tmp->next;
    }
}