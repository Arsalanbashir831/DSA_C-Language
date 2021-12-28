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

int main(int argc, char const *argv[])
{
 struct Node * list1=NULL;
    list1=insertNode(list1,1);
    list1=insertNode(list1,2);
    list1=insertNode(list1,3);
    list1=insertNode(list1,9);
   list1=reverse(list1);
    traverse(list1);
    return 0;
}
