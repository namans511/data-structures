#include <stdio.h>
#include <stdlib.h>
// #include <bits/stdc++.h>
struct Node {
    int data;
    struct Node* next;
};

struct Node* create() {
    struct Node *ptr=(struct Node*)malloc(sizeof(struct Node));
    ptr->next=NULL;
    return ptr;
} 

void push(struct Node **head, int value) {
    struct Node *temp=create();
    temp->data=value;
    if(head) temp->next=*head;
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
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
    printf("\n\n\n");
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
