#include "linked.h"

typedef struct Node* node;

void frontBackSplit(node* head, node* a, node* b) {
    if(*head == NULL || (*head)->next==NULL) {
        *a = *head;
        *b = NULL;
        return;
    }

    node fast, slow;
    fast = *head;
    slow = *head;

    while(fast->next) {
        fast=fast->next;
        if(fast->next) {
            slow=slow->next;
            fast=fast->next;
        }
    }
    *a = *head;
    *b = slow->next;
    slow->next = NULL;
}


void sortedMerge(node* a, node* b) {
    if(!(*a) && !(*b)) return;
    node x = create();
    node head=x;
    while((*a) && (*b)) {
        if((*a)->data < (*b)->data) {
            x->next=*a;
            *a=(*a)->next;
        }
        else {
            x->next=*b;
            *b=(*b)->next;
        }
        x=x->next;
        x->next=NULL;
    }
    if(*b) *a=*b;
    if(*a) x->next=*a;
    *a=head->next;
}

void mymergesort(node* head) {
    if(!(*head) || !((*head)->next)) return;
    node a,b;
    frontBackSplit(head,&a,&b);
    mymergesort(&a);
    mymergesort(&b);
    sortedMerge(&a,&b);
    *head=a;
}

int main(int argc, char const *argv[])
{
    int c=3;
    node head;

    while(c) {
        printf("1:push, 2:print, 3:pop, 4:reverse,5:sort 0:quit\n");
        scanf("%d",&c);
        switch(c) {
            case 1:
                printf("enter number\n");
                int x;
                scanf("%d",&x);
                push(&head,x);
                break;
            case 2:
                traverse(&head);
                break;
            case 3:
                pop(&head);
                break;
            case 4:
                reverse(&head);
                break;
            case 5:
                mymergesort(&head);
                break;
            default:
                printf("lmao wut\n");
        }
    }
    return 0;
}

// int main(int argc, char const *argv[])
// {
//     freopen("/Users/namansrivastava/Documents/projects/datastr/bin/input.txt", "r", stdin); 
//     freopen("/Users/namansrivastava/Documents/projects/datastr/bin/output.txt", "w", stdout); 
//     int n;
//     cin>>n;
//     node head;
//     while(n--) {
//         int x;
//         cin>>x;
//         push(&head, x);
//     }
//     mymergesort(&head);
//     return 0;
// }

// node getNode(node ptr, int n) {
//     int i=0;
//     while(ptr) {
//         if(i == n) return ptr;
//         ptr =  ptr->next;
//         i++;
//     }
//     return NULL;
// }

// int getLength(node ptr) {
//     int i=0;
//     while(ptr) {
//         ptr =  ptr->next;
//         i++;
//     }
//     return i;
// }

// int getIndex(node a) {
//     int i=0;
//     node ptr = head;
//     while(ptr && ptr!=a) {
//         i++;
//         ptr=ptr->next;
//     }
//     return i;
// }

