
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};
//inserting the node sequentially.
struct Node *insertNode(struct Node *head, int data)
{
    struct Node *newNode=(struct Node*)malloc(sizeof(struct Node));
    struct Node *ptr=head;
    // if the head node is NULL than we will insert the node at first.
  if(head==NULL){
     newNode->data=data;
    newNode->next=head;
    head=newNode;
  }
  //if not NULL than we will insert the node at end ..
  else{
    while (ptr->next!=NULL)
    {
        ptr=ptr->next;
    }
    newNode->data=data;
    newNode->next=ptr->next;
    ptr->next=newNode;
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
void taversal(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("%d   ", ptr->data);
        ptr = ptr->next;
    }
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
int main()
{

  struct Node* list_1=NULL;
  struct Node * list_2=NULL;
  list_1=insertNode(list_1,3);
  list_1=insertNode(list_1,5);
  list_1=insertNode(list_1,2);
  list_1=insertNode(list_1,7);
  list_1=insertNode(list_1,1);
  list_2=insertNode(list_2,6);
  list_2=insertNode(list_2,9);
  list_2=insertNode(list_2,11);
  list_2=insertNode(list_2,43);
  list_2=insertNode(list_2,90);
  printf("\n==========List 1=======\n");
  taversal(list_1);
  printf("\n==========List 2=======\n");
  taversal(list_2);
  printf("\n==========Concat=======\n");
  list_1=concat(list_1,list_2);
  taversal(list_1);
struct Node *unsort=NULL;
unsort=insertNode(unsort,3);
  unsort=insertNode(unsort,5);
  unsort=insertNode(unsort,2);
  unsort=insertNode(unsort,7);
  unsort=insertNode(unsort,4);
  printf("\nNodes before sorting\n");
  taversal(unsort);
  unsort=sort(unsort);
   printf("\nNodes after sorting\n");
    taversal(unsort);
    return 0;
}