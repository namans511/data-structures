#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};
struct Node *head;

struct Node* create(int value) {
    struct Node *ptr=(struct Node*)malloc(sizeof(struct Node));
    ptr->data=value;
    ptr->next=NULL;
    return ptr;
} 

void push(int value) {
    struct Node *temp=create(value);
    temp->next=head;
    head=temp;
}

void delete() {
    if(!head) {
        printf("underflow\n");
        return;
    }
    struct Node *ptr=head;
    head=head->next;
    free(ptr);
}

void traverse() {
    struct Node *ptr=head;
    printf("linked list:\n");
    while(ptr) {
        printf("%d\n",ptr->data);
        ptr=ptr->next;
    }
}

void reverse() {
    struct Node *prevPtr, *currPtr, *nextPtr;
    currPtr=head;
    prevPtr=NULL;
    while(currPtr) {
        nextPtr=currPtr->next;
        currPtr->next=prevPtr;
        prevPtr=currPtr;
        currPtr=nextPtr;
    }
    head=prevPtr;
}

void func(struct Node *ptr) {
    if(ptr == NULL) {
        return;
    }
    func(ptr->next);
    printf("%d ",ptr->data);
}

// int main(int argc, char const *argv[])
// {
//     int c=3;
//     while(c) {
//         printf("1:push, 2:print, 3:delte, 4:reverse, 0:quit\n");
//         scanf("%d",&c);
//         switch(c) {
//             case 1:
//                 printf("enter number\n");
//                 int x;
//                 scanf("%d",&x);
//                 push(x);
//                 break;
//             case 2:
//                 traverse();
//                 break;
//             case 3:
//                 delete();
//                 break;
//             case 4:
//                 reverse();
//                 break;
//             case 5:
//                 func(head);
//                 break;
//             default:
//                 printf("lmao wut\n");
//         }
//     }
//     return 0;
// }