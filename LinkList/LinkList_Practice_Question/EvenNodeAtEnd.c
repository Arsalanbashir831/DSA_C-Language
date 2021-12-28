#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
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

struct Node *EvenAtEnd(struct Node *head,struct Node *EvenList,struct Node *OddList){
struct Node *ptr=head;
while (ptr!=NULL)
{
    if (ptr->data%2==0)
    {
        EvenList=insertNode(EvenList,ptr->data);
         ptr=ptr->next;
    }
    else
    {
        OddList=insertNode(OddList,ptr->data);
         ptr=ptr->next;
    }
}
OddList=concat(OddList,EvenList);
return OddList;
}
int main(int argc, char const *argv[])
{
   struct Node * list1=NULL;
    list1=insertNode(list1,1);
    list1=insertNode(list1,2);
    list1=insertNode(list1,4);
    list1=insertNode(list1,8);
    list1=insertNode(list1,3);
    list1=insertNode(list1,9);
     printf("\nList mix Even and Odd numbers in list");
     printf("\n");
    traverse(list1);
    struct Node * result=NULL;
    struct Node * Even=NULL;
    struct Node * Odd=NULL;
    printf("\nEven at the end of the list\n");
    result=EvenAtEnd(list1,Even,Odd);
    traverse(result);
    return 0;
}

