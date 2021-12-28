#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
void traverse(struct Node *head)
{
    struct Node *ptr = head;
    while (ptr != NULL)
    {
        printf("%d  ", ptr->data);
        ptr = ptr->next;
    }
}
// inserting the node sequentially.
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
int counter(struct Node *head)
{
    int i = 0;
    struct Node *p = head;
    while (p != NULL)
    {
        p = p->next;
        i++;
    }
    return i;
}
void split(struct Node *l1)
{
    struct Node *l1_curr=l1;
    struct Node *l2=NULL;
    struct Node *l3 = NULL;
    for (int i = 0; i <= counter(l1)/3-1; i++)
    {
        l1_curr = l1_curr->next;
    }
    
    l2 = l1_curr->next;
    l1_curr->next =  NULL;
    l1_curr = l2;

    for (int i = 0; i < counter(l1)/3 -1; i++)
    {
        l1_curr = l1_curr->next;
    }

    l3 = l1_curr->next;
    l1_curr->next = NULL;
    l1_curr = l3;
    
    printf("\nList 1 \n");
    traverse(l1);
    printf("\nList 2 \n");
    traverse(l2);
    printf("\nList 3 \n");
    traverse(l3);
}
int main()
{
    struct Node *l1 = NULL;
    l1 = insertNode(l1, 1);
    l1 = insertNode(l1, 2);
    l1 = insertNode(l1, 3);
    l1 = insertNode(l1, 9);
    l1 = insertNode(l1, 7);


    // printf("\n %d", counter(l1));
    printf("\n");
    split(l1);
    
    return 0;
}