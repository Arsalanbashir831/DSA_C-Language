#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};

void taversal(struct Node *head)
{
    struct Node *temp = head;
    while (temp != 0)
    {
        printf("%d  ", temp->data);
        temp = temp->next;
    }
}
struct Node *insertAtFirst(struct Node *head,int data){

    struct Node *temp=head;
    struct Node * ptr=(struct Node*)malloc(sizeof(struct Node));
    ptr->data=data;
    head->prev=ptr;
    ptr->next=head;
    head=ptr;
    return head;
}

int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;

    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));

    head->data = 4;
    head->prev = NULL;
    head->next = second;

    second->data = 11;
    second->prev = head;
    second->next = third;

    third->data = 78;
    third->prev = second;
    third->next = fourth;

    fourth->data = 90;
    fourth->prev = third;
    fourth->next = NULL;

    printf("Traverse the list :\n");
    taversal(head);
    printf("\ninset at the list :\n");
    head=insertAtFirst(head,43);
      taversal(head);

    return 0;
}