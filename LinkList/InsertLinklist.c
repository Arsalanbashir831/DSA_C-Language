#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void taversal(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("%d   ", ptr->data);
        ptr = ptr->next;
    }
}
struct Node *insertAtFirst(struct Node *head, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));

    ptr->next = head;
    ptr->data = data;
    head = ptr;
    return head;
}

struct Node *insertAtIndex(struct Node *head, int index, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node *p = head;
    int i = 0;
    while (i != index - 1)
    {
        p = p->next;
        i++;
    }
    ptr->data = data;
    ptr->next = p->next;
    p->next = ptr;
    return head;
}

struct Node *insertAtEnd(struct Node *head, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node *prev = head;
    ptr->data = data;
    while (prev->next != NULL)
    {
        prev = prev->next;
    }
    prev->next = ptr;
    ptr->next = NULL;
    return head;
}

struct Node *insertAfter(struct Node*head,int data,int index){
      struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node *p = head;
    int i = 0;
    while (i != index)
    {
        p = p->next;
        i++;
    }
     ptr->data = data;
    ptr->next = p->next;
    p->next = ptr;
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
    head->next = second;

    second->data = 11;
    second->next = third;

    third->data = 78;
    third->next = fourth;

    fourth->data = 90;
    fourth->next = NULL;

    taversal(head);
    printf("\n");
    //insert  at first
    head = insertAtFirst(head, 32);
    //insert at between
    head = insertAtIndex(head, 2, 90);
    //insert at end
    head = insertAtEnd(head, 921);
   // insert after the given index
    head=insertAfter(head,43,2);
    taversal(head);
    return 0;
}