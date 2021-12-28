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
int main()
{
    struct Node * list1=NULL;
   struct Node * list2=NULL;
    list1=insertNode(list1,1);
    list1=insertNode(list1,2);
    list1=insertNode(list1,3);
    list1=insertNode(list1,9);
    printf("\n======List 1=====\n");
    traverse(list1);
    list2=insertNode(list2,4);
    list2=insertNode(list2,5);
    list2=insertNode(list2,6);
    printf("\n======List 2=====\n");
    traverse(list2);
       printf("\n======Concat List=====\n");
   list1= concat(list1,list2);
     traverse(list1);

    return 0;
}