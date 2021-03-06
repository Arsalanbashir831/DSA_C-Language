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
void reverse(struct Node *head)
{

    struct Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    while (temp != head)
    {
        printf("%d  ", temp->data);
        temp = temp->prev;
    }
    printf("%d  ", temp->data);
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
    printf("\n reverse the List :\n");
    reverse(head);

    return 0;
}