#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};
int counter (struct Node *ptr){
    int i=0;
     while (ptr != NULL)
    {
        printf("%d   ", ptr->data);
        ptr = ptr->next;
        i++;
    }
    return i;
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
struct Node *concat(struct Node *list1, struct Node *list2) {
    struct Node *list1_curr=list1;
    //reaching at the second last node by using the pointer list1.
    while (list1_curr->next!=NULL)
    {
        list1_curr=list1_curr->next;
    }
    //link the list1 with list2
    list1_curr->next=list2;
    return list1;
}
struct Node *traverse(struct Node *head){
      struct Node *pointer=head;
      //simply traverse the list by reading the list using the pointer.
      while (pointer!=NULL)
      {
          printf("%d  ",pointer->data);
          pointer=pointer->next;
      }
      return head;
      
}
struct Node *reverse(struct Node *head){
   struct Node * curr=head;
   struct Node *next=NULL;
   struct Node* prev=NULL;

   while (curr!=NULL)
   {
       next=curr->next;
       curr->next=prev;
       prev=curr;
       curr=next;
   }
   head=prev;
   return head;   
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
struct Node *sort(struct Node *head)
{
    struct Node *p = head;
    struct Node *q = p->next;
    while (p->next != NULL)
    {
        q = p->next;
        while (q != NULL)
        {
            if (p->data > q->data)
            {
                int temp;
                temp = q->data;
                q->data = p->data;
                p->data = temp;
            }
            q = q->next;
        }
        p = p->next;
    }
    return head;
}