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

struct Node *insertAfter(struct Node *head, int data, int index)
{
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
    int opt, num, index;
    printf("By default value Before Insertion in linklist\n");
    taversal(head);
    printf("\n");
    
    
    while (1)
    {
         printf("\n1-insert at first\n2-insert at index\n3-insert at end\n4-insert at after index\n5-display\n");
        scanf("%d", &opt);
        if (opt == 1)
        {
            printf("enter the value");
            scanf("%d", &num);
            head = insertAtFirst(head, num);
        }
        if (opt == 2)
        {
            printf("enter the value");
            scanf("%d", &num);
            printf("Enter the index");
            scanf("%d", &index);
            head = insertAtIndex(head, index, num);
        }
        if (opt == 3)
        {
            head = insertAtEnd(head, num);
            printf("%d is inserted at end", num);
        }
        if (opt == 4)
        {
            printf("enter the value");
            scanf("%d", num);
            printf("Enter the index");
            scanf("%d", &index);
            head = insertAfter(head, num, index);
            printf("%d is inserted after the %d", num, index);
        }

        if (opt == 5)
        {
            taversal(head);
        }

        if (opt == -1)
        {
            break;
        }
    }
    return 0;
}
