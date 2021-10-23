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

struct Node *deleteAtFirst(struct Node *head)
{
    struct Node *ptr = head;
    head = head->next;
    free(ptr);
    return head;
}

struct Node *deleteAtIndex(struct Node *head, int index)
{

    struct Node *ptr = head;
    struct Node *delNode = ptr->next;
    int i = 0;
    while (i != index - 1)
    {
        ptr = ptr->next;
        i++;
    }
    ptr->next = delNode->next;
    free(delNode);
    return head;
}
struct Node *deleteAtLast(struct Node *head)
{
    struct Node *ptr = head;
    while (ptr->next->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr->next = NULL;
    return head;
}

struct Node *deleteByValue(struct Node *head, int data)
{
    struct Node *ptr = head;
    struct Node *q = head->next;                                                                                                                                                                                                                                                                        

    while (q->data != data && q->next != NULL)
    {

        ptr = ptr->next;
        q = q->next;
    }
    if (q->data == data)
    {
        ptr->next = q->next;
        free(q);
    }

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
    // head=deleteAtFirst(head);
    //delete at given index
    // head=deleteAtIndex(head,1);
    //delete at last index
    // head=deleteAtLast(head);
    head = deleteByValue(head, 78);
    taversal(head);
    return 0;
}