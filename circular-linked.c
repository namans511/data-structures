#include "linked.h"

void pushCir(node **head,int value) {
    node *temp = create();
    temp->data=value;
    if(!(*head)) {
        temp->next=temp;
        *head=temp;
    } else {
        temp->next=(*head)->next;
        (*head)->next=temp;
    }
}

void traverseCir(node **head) {
    printf("lol\n");
    node *ptr=*head;
    while(ptr && ptr->next!=(*head)) {
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
}

//lmao

int main(int argc, char const *argv[])
{
    node *head;
    pushCir(&head, 5);
    pushCir(&head, 6);
    pushCir(&head, 3);
    traverseCir(&head);
    return 0;
}