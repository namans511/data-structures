#include <stdio.h>
#include <stdlib.h>

struct Node
{
    struct Node* next;
    struct Node* prev;
    int data;
}*head;

struct Node* create(int value) {
    struct Node *ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->data=value;
    return ptr;
}

void push(int value) {
    struct Node *ptr=create(value);
    if(head) {
        head->prev=ptr;
    }
    ptr->next=head;
    head = ptr;
}

void pop() {
    if(head) {
        struct Node *ptr=head;
        head=head->next;
        free(ptr);
    }
}

void traverse() {
    struct Node *ptr = head;
    printf("-------------\n");
    while(ptr) {
        printf("%d\n",ptr->data);
        ptr=ptr->next;
    }
    printf("-------------\n");
}