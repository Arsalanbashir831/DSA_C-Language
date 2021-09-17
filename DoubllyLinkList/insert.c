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
struct Node *insertAtFirst(struct Node *head,int data){

    struct Node *temp=head;
    struct Node * ptr=(struct Node*)malloc(sizeof(struct Node));
    ptr->data=data;
    head->prev=ptr;
    ptr->next=head;
    head=ptr;
    return head;
}
struct Node *insertAtIndex(struct Node *head,int data,int index){

    struct Node *temp=head;
   
    struct Node * ptr=(struct Node*)malloc(sizeof(struct Node));
    ptr->data=data;
   int i=0;
   if (index==0)
   {
       head=insertAtFirst(head,data);
       return head;
   }
   else
   {
       while (i!=index-1)
       {
              temp=temp->next;
              i++;      
       }
        ptr->prev=temp;
        ptr->next=temp->next;
        temp->next=ptr;
        ptr->next->prev=ptr;
return head;
   
   }
   
   return head;
}
struct Node * insertAtEnd(struct Node *tail,int data){
      struct Node * ptr=(struct Node*)malloc(sizeof(struct Node));
    ptr->data=data;
    tail->next=ptr;
    ptr->prev=tail;
    tail=ptr;
}
int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *tail;

    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    tail = (struct Node *)malloc(sizeof(struct Node));

    head->data = 4;
    head->prev = NULL;
    head->next = second;

    second->data = 11;
    second->prev = head;
    second->next = third;

    third->data = 78;
    third->prev = second;
    third->next = tail;

    tail->data = 90;
    tail->prev = third;
    tail->next = NULL;

    printf("Traverse the list :\n");
    taversal(head);
    printf("\ninset at the list :\n");
    // head=insertAtFirst(head,43);
    head=insertAtIndex(head,43,2);
     tail=insertAtEnd(tail,54);
      taversal(head);

    return 0;
}