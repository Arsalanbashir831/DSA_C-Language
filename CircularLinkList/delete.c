#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void taversal(struct Node *head)
{
    struct Node *ptr = head;
    do
    {
        printf("%d   ", ptr->data);
        ptr = ptr->next;

    } while (ptr != head);
}
struct Node *deleteAtFirist(struct Node *head)
{
    struct Node *ptr = head;
    struct Node *q = ptr->next;
    while (ptr->next != head)
    {
        ptr = ptr->next;
        q = q->next;
    }

    head = q->next;
    ptr->next = q->next;
    free(q);
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
    fourth->next = head;

    taversal(head);
    printf("\n");
    head = deleteAtFirist(head);
    taversal(head);

    return 0;
}