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



int main(int argc, char const *argv[])
{
    // freopen("/Users/namansrivastava/Documents/projects/datastr/bin/input.txt", "r", stdin); 
    // freopen("/Users/namansrivastava/Documents/projects/datastr/bin/output.txt", "w", stdout); 
    int c=1;
    while(c) {
        printf("1:push, 2:print, 3:delte, 4:reverse, 0:quit -->");
        scanf("%d",&c);
        switch(c) {
            case 1:
                printf("enter number: ");
                int x;
                scanf("%d",&x);
                push(x);
                break;
            case 2:
                traverse();
                break;
            case 3:
                pop();
                break;
            // case 4:
            //     reverse();
            //     break;
            default:
                printf("lmao wut\n");
        }
    }
    return 0;
}