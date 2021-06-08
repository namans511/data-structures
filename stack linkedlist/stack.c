#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node *next;
} *head;

struct Node* createPtr(int value) {
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data=value;
    ptr->next=NULL;
}

void push(int value) {
    struct Node *ptr = createPtr(value);
    ptr->next=head;
    head = ptr;
}