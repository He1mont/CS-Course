#include <stdio.h>
#include <stdlib.h>

// STRUCTURE
typedef struct _node{
    int value;
    struct _node *next;     // 一个指针指向下一个这样的结构
} Node;

typedef struct _list{       // 定义自己的数据结构来代表整个list
    Node* head;
    // Node* tail;
} List;

// FUNCTION
void add(List* pList, int number);
void display(List *pList);

// MAIN
int main(int argc, char const *argv[])
{
    List list;
    list.head = NULL;
    // list.tail = NULL;

    int number;

    do {
        printf("Please type a number: ");
        scanf("%d", &number);
        if (number != -1 ){
            add(&list, number);  // 传入head的指针
        }
    }while(number != -1);

    display(&list);
    printf("Please type a number you wanna find: ");
    scanf("%d", &number);

    return 0;
}

void add(List* pList, int number)
{
    // add to linked list
    Node *p = (Node*) malloc(sizeof(Node));
    p->value = number;
    p->next = NULL;

    // find the last and link
    // 每次链表增加新元素时，找到当前的最后的一个元素并于新元素link上

    Node *last = pList->head;      // last指向head所指向的元素

    if (last != NULL){      // 第一次开始找的时候last = NULL
        while (last -> next != NULL ) {
            last = last->next;      // 往下指一位
        }
        // attach
        last -> next = p;
    } else {
        pList->head = p;           // 原来head什么都没指，让head指向第一个元素
    }
}

void display(List *pList)
{
    // 在链表当中遍历的经典写法
    Node *p;
    printf("\nHere is the list: \n");
    for (p=pList->head; p; p=p->next){    // p stands for p!=NULL
        printf("%d ", p->value);
    }
    printf("\n\n");
}

void find(List *pLise)
{
    Node *p;

}