#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node * next;
};

void taversal(struct Node *ptr){
    while (ptr!=NULL)
    {
        printf("%d   ", ptr->data);
        ptr = ptr->next;
       
    }
    
}

int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;

    head=(struct Node *)malloc(sizeof(struct Node));
    second=(struct Node *)malloc(sizeof(struct Node));
    third=(struct Node *)malloc(sizeof(struct Node));
    fourth=(struct Node *)malloc(sizeof(struct Node));

    head->data=4;
    head->next=second;

    second->data=11;
    second->next=third;

    third->data=78;
    third->next=fourth;

    fourth->data=90;
    fourth->next=NULL;

    taversal(head);

return 0;

}