// 20411905 scygs2 Guosheng SU

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char *name;
    char *pNum;
    char *email;
    char *dep;
    struct Node *pre;
    struct Node *next;
}node;

// Functions 
void menu(void);
void display(node **head_ref);      // option 1

int main(void)
{   
    // user's option
    int opt;
    node *head = NULL;      // define a struct pointer

    do {
        opt = 0;
        menu();
        scanf("%d", &opt);

        if (opt == 1){
            display(&head);

        } else if (opt == 2){
            add();

        } else if (opt == 3){
            printf("Option 3\n");

        } else if (opt == 4){
            printf("Option 4\n");

        } else if (opt == 5){
            printf("Option 5\n");

        } else if (opt == 6){
            exit(0);

        } else {
            printf("Unknown option!\n\n");  // to be complete
        }
    }while (1);

    return 0;
}

void menu(void){
    printf("1) Print contact list\n");
    printf("2) Add a contact\n");
    printf("3) Modify a contact\n");
    printf("4) Delete a contact\n");
    printf("5) Search\n");
    printf("6) Quit\n");
    printf("Option: ");
}

void display(node **head_ref)
{
    node *tmp = *head_ref;

    while (tmp != NULL){
        printf("%s\t%s\t%s %s\n",
            tmp->pNum, tmp->email, tmp->name, tmp->dep);
        tmp = tmp->next;
    }

}