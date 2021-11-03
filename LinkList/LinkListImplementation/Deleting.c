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
printf("BY default our linklist \n");
    taversal(head);
    printf("\n");
    int opt,value,index;
    printf("\n1-delete at first\n2-delete at any position\n3-delete by value\n4-delete last \n5-number of nodes\n6-display the list\n-1 to exit");
   while (opt!=-1)
   {
       if (opt==1)
       {
           // delete  at first
    head=deleteAtFirst(head);
       }
       if (opt==2)
       {
           printf("Enter the position");
           scanf("%d",&index);
          // delete at given index
    head=deleteAtIndex(head,index);
       }
       if (opt==3)
       {
           //delete by value 
           printf("Enter the value");
           scanf("%d",value);
             head = deleteByValue(head, 78);
            
       }
       
       if (opt==4)
       {
 // delete at last index
    head=deleteAtLast(head);       }
       
   }
   if (opt==5)
   {
taversal(head);

printf("\nNumber of nodes in the list : %d\n",counter(head));
   }
   
     

    
   
    
  
    return 0;
}