// A complete working C program to demonstrate all insertion methods 
#include <stdio.h> 
#include <stdlib.h> 

// A linked list node 
struct Node { 
	int data; 
	struct Node* next; 
	struct Node* prev; 
}; 

// Function
void InsertAtBegining(struct Node** head_ref, int new_data);
void insertEnd(struct Node** head_ref, int new_data);
void insertAfterIndex(struct Node** head_ref, int new_data, int index);
void deleteNode(struct Node** head_ref, struct Node* del);
void deleteNodeAtGivenIndex(struct Node** head_ref, int index);
void printList(struct Node* node);

/* Driver program to test above functions*/
int main(void) 
{ 
	/* start always points to the first node of the linked list.
           temp is used to point to the last node of the linked list.*/
    int query;
    struct Node* head = NULL;
    /* Here in this code, we take the first node as a dummy node.
        The first node does not contain data, but it used because to avoid handling special cases in insert and delete functions.
        */
    printf("1. Insert at begining\n");
    printf("2. Insert at the end\n");
    printf("3. Insert after index\n");
    printf("4. Delete At Index\n");
    printf("5. Print\n");
    printf("6. Exit\n");

    do{
        printf("Enter your choice: ");
        scanf("%d",&query);
        if(query==1)
        {
            int data;
            printf("Enter a number: ");
            scanf("%d",&data);
            InsertAtBegining(&head,data);
        }
        else if(query==2)
        {
            int data;
            printf("Enter a number: ");
            scanf("%d",&data);
            insertEnd(&head,data);
        }
        else if(query==3)
        {
            int data, index;
            printf("Enter a number and Index: ");
            scanf("%d%d",&data, &index);
            insertAfterIndex(&head,data,index);
        }
        else if(query==4)
        {
            int index;
            printf("Enter an Index: ");
            scanf("%d",&index);
            deleteNodeAtGivenIndex(&head,index);
        }
        else if(query==5)
        {
            printf("The list is ");
            printList(head);
            printf("\n");
        }
        else if(query==6)
        {
            exit(0);
        }
        else
        {
            printf("Invalid input.\n");
        }
    }while(1);

    return 0;
} 

/* Given a reference (pointer to pointer) to the head of a list 
and an int, inserts a new node on the front of the list. */
void InsertAtBegining(struct Node** head_ref, int new_data) 
{
	/* 1. allocate node */
	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node)); 

	/* 2. put in the data */
	new_node->data = new_data; 

	/* 3. Make next of new node as head and previous as NULL */
    new_node->next = (*head_ref); 
    new_node->prev = NULL; 

	/* 4. change prev of head node to new node */
	if ((*head_ref) != NULL) 
		(*head_ref)->prev = new_node; 

	/* 5. move the head to point to the new node */
	(*head_ref) = new_node; 
} 

/* Given a reference (pointer to pointer) to the head 
of a DLL and an int, appends a new node at the end */
void insertEnd(struct Node** head_ref, int new_data) 
{ 
	/* 1. allocate node */
	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node)); 

	struct Node* last = *head_ref; /* used in step 5*/
    // here last is a temporary pointer

	/* 2. put in the data */
	new_node->data = new_data; 

	/* 3. This new node is going to be the last node, so 
		make next of it as NULL*/
	new_node->next = NULL; 

	/* 4. If the Linked List is empty, then make the new 
		node as head */
	if (*head_ref == NULL) { 
		new_node->prev = NULL; 
		*head_ref = new_node; 
		return; 
	} 

	/* 5. Else traverse till the last node */
	while (last->next != NULL) 
		last = last->next; 

	/* 6. Change the next of last node */
	last->next = new_node; 

	/* 7. Make last node as previous of new node */
	new_node->prev = last; 

	return; 
} 

/* Given a reference (pointer to pointer) to the head 
of a DLL and an int and index, inserts a new node after the index */
void insertAfterIndex(struct Node** head_ref, int new_data, int index) 
{ 
	/* 1. allocate new node */
	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node)); 

        /* 2. if list in NULL or invalid position is given */
        if (*head_ref== NULL || index < 0)
           return;

        struct Node* current = *head_ref;
        int i;

        /* 3. traverse up to the node at position 'index' from the beginning */
        for (i= 0; current != NULL && i< index; i++)
           current = current->next;

        /* 4. if 'index' is greater than the number of nodes in the doubly linked list */
        if (current == NULL)
           return;

	/* 5. put in the data */
	new_node->data = new_data; 

	/* 6. Make next of new node as next of prev_node */
	new_node->next = current->next; 

	/* 7. Make the next of prev_node as new_node */
	current->next = new_node; 

	/* 8. Make prev_node as previous of new_node */
	new_node->prev = current; 

	/* 9. Change previous of new_node's next node */
	if (new_node->next != NULL) 
		new_node->next->prev = new_node; 
}

void deleteNode(struct Node** head_ref, struct Node* del)
{
    /* base case */
    if (*head_ref== NULL || del == NULL)
    return;

    /* If node to be deleted is head node */
    if (*head_ref== del)
        *head_ref= del->next;

    /* Change next only if node to be deleted is NOT the last node */
    if (del->next != NULL)
        del->next->prev= del->prev;

    /* Change prevonly if node to be deleted is NOT the first node */
    if (del->prev!= NULL)
        del->prev->next = del->next;

    /* Finally, free the memory occupied by del*/
    free(del);
    return;
}

void deleteNodeAtGivenIndex(struct Node** head_ref, int index)
{
    /* if list in NULL or invalid index is given */
    if (*head_ref== NULL || index < 0)
        return;

    struct Node* current = *head_ref;
    int i;

    /* traverse up to the node at position 'index' from the beginning */
    for (i= 0; current != NULL && i< index; i++)
        current = current->next;

    /* if 'index' is greater than the number of nodes in the doubly linked list */
    if (current == NULL)
        return;

    /* delete the node pointed to by 'current' */
    deleteNode(head_ref, current);
}

// This function prints contents of linked list starting from the given node 
void printList(struct Node* node) 
{ 
	struct Node* last; 
	printf("\nTraversal in forward direction \n"); 
	while (node != NULL) { 
		printf(" %d ", node->data); 
		last = node; 
		node = node->next; 
	} 

	printf("\nTraversal in reverse direction \n"); 
	while (last != NULL) { 
		printf(" %d ", last->data); 
		last = last->prev; 
	} 
} 