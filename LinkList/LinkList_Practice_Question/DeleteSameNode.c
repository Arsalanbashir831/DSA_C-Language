#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *insertNode(struct Node *head, int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    struct Node *ptr = head;
    // if the head node is NULL than we will insert the node at first.
    if (head == NULL)
    {
        newNode->data = data;
        newNode->next = head;
        head = newNode;
    }
    // if not NULL than we will insert the node at end ..
    else
    {
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        newNode->data = data;
        newNode->next = ptr->next;
        ptr->next = newNode;
    }
    return head;
}
struct Node *traverse(struct Node *head)
{
    struct Node *pointer = head;
    // simply traverse the list by reading the list using the pointer.
    while (pointer != NULL)
    {
        printf("%d  ", pointer->data);
        pointer = pointer->next;
    }
    return head;
}
struct Node *delSameNodes(struct Node *head)
{
    struct Node *ptr1 = head;
    struct Node *ptr2;
    while ( ptr1 != NULL)
    {
      ptr2=ptr1;
        while (ptr2->next != NULL)
        {
            if (ptr1->data == ptr2->next->data)
            {
                ptr2->next = ptr2->next->next;
            }
            else
            {
                ptr2 = ptr2->next;
            }
        }
        ptr1 = ptr1->next;
    }
    return head;
}
int main(int argc, char const *argv[])
{
    struct Node *list = NULL;
    list = insertNode(list, 1);
    list = insertNode(list, 2);
    list = insertNode(list, 2);
    list = insertNode(list, 8);
    list = insertNode(list, 8);
    printf("Before deletion\n");
    list = traverse(list);
    printf("\n delete same nodes\n");
    list = delSameNodes(list);
    list = traverse(list);
    return 0;
}
