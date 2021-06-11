#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
}node;

struct Node* create() {
    struct Node *ptr=(struct Node*)malloc(sizeof(struct Node));
    ptr->next=NULL;
    return ptr;
} 

void push(struct Node **head, int value) {
    struct Node *temp=create();
    temp->data=value;
    temp->next=*head;
    *head=temp;
}

void pop(struct Node **head) {
    if(!(*head)) {
        printf("underflow\n");
        return;
    }
    struct Node *ptr=*head;
    *head=(*head)->next;
    free(ptr);
}

void traverse(struct Node **head) {
    struct Node *ptr=*head;
    printf("linked list:\n");
    while(ptr) {
        printf("%d\n",ptr->data);
        ptr=ptr->next;
    }
}

void reverse(struct Node **head) {
    struct Node *prevPtr, *currPtr, *nextPtr;
    currPtr=*head;
    prevPtr=NULL;
    while(currPtr) {
        nextPtr=currPtr->next;
        currPtr->next=prevPtr;
        prevPtr=currPtr;
        currPtr=nextPtr;
    }
    *head=prevPtr;
}
