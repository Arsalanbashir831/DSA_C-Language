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
void Search(struct Node *head, int data)
{
    struct Node *node_ptr = head;
    int flag = 0;
    while (node_ptr != NULL)
    {
        if (node_ptr->data == data)
        {
            flag = 1;
            printf("\n%d is found ", data);
        }
        node_ptr = node_ptr->next;
    }
    if (flag == 0)
    {
        printf("no data found");
    }
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
    printf("Enter the data to search : ");
    int data;
    scanf("%d", &data);
    Search(head, data);
    return 0;
}