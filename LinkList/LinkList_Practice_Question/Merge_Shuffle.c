#include <stdio.h>
#include <conio.h>
#include<stdlib.h>
typedef struct Node
{
    int data;
    struct Node *next;
} Node;



int getLength(Node *head)
{
    Node *temp = head;
    int i;
    for (i = 0; temp != NULL; i++)
    {
        temp = temp->next;
    }
    return i;
}

int isEmptySingly(Node *head)
{
    return getLength(head) == 0;
}

Node* insertFrontSingly(Node *head, int data)
{
    if (head == NULL) //for first element
    {
       createNode(head);
    }   
    else
    {
        Node *iterator = head; //iterating till empty node is found
        Node *newNode = (Node *)malloc(sizeof(Node));
        newNode->data = data;
        newNode->next = NULL;

        while (iterator->next != NULL)
        {
            iterator = iterator->next;
        }
        iterator->next = newNode; //adding node at end
    }
    return head;

}



Node* insertBackSingly(Node *head, int data)
{
    if (head == NULL) //for first element
    {
        head = (Node *)malloc(sizeof(Node)); //making a new node
        head->data = data;                   //inserting data
        head->next = NULL;
        return head;
    }
    else
    {
        Node *newNode = (Node *)malloc(sizeof(Node));
        newNode->data = data;
        newNode->next = head;

        head = newNode; //changing head to first pointer again
    }
    return head;

}
void insertAtSingly(Node* head, int data, int index)
{
    if (index > getLength(head))
    {
        printf("\n-----------Index overflow-------------\n");
        return ;
    }

    else if (index == 0)
    {
        insertBackSingly(head,data);
    }
    else if (index == getLength(head))
    {
        insertFrontSingly(head,data);
    }
    else
    {
        Node *newNode = (Node *)malloc(sizeof(Node));
        newNode->data = data;
        Node *iterator = head;

        for (int i = 1; i < index - 1; i++)
        {
            iterator = iterator->next;
        }
        newNode->next = iterator->next;
        iterator->next = newNode;
    }
}
void displaySingly(Node *head)
{
    printf("-------------------------------------\n");
    Node *iterator = head;
    while (iterator != NULL)
    {
        printf("Data is %d\n", iterator->data); //display data at each node till its null
        iterator = iterator->next;
    }
    printf("-------------------------------------\n");
}

Node* deleteFirstSingly(Node* head)
{
    Node *temp = head;
    if (head != NULL) //changing head
    {
        head = head->next;
        return head;
    }
    else
    {
        return NULL;
    }
}

Node* deleteLastSingly(Node *head)
{
    Node *iterator = head;
    if (head == NULL)
    {
        return NULL;
    }

    if (iterator->next == NULL) //for a single element aka only head
    {
        head = NULL;
        free(head); //freeing memory
        return head;
    }
    else
    {

        while (iterator->next->next != NULL) //iterating for multiple elements
        {
            iterator = iterator->next;
        }
        Node *temp = iterator->next;
        iterator->next = NULL;
        free(iterator->next);
        return head;
    }
}

int deleteAtSingly(Node *head, int index)
{
    if (index >= getLength(head))
    {
        printf("\n-----------Index overflow-------------\n");
        return -1;
    }

    Node *iterator = head;
    {
        for (int i = 1; i < index - 1; i++)
        {
            iterator = iterator->next;
        }
        Node *temp = iterator->next;
        iterator->next = iterator->next->next;
        return temp->data;
    }
}


void shuffleMerge(Node* head1 , Node* head2)
{
    while (head2 != NULL)
    {
        insertAtSingly(head1,head2->data,rand()%getLength(head1));
        head2 = deleteFirstSingly(head2);
    }

    displaySingly(head1);
    
}
int main(int argc, char const *argv[])
{
    Node* head1 = NULL;
    Node* head2 = NULL;

    head1 = insertFrontSingly(head1,1);
    head1 = insertFrontSingly(head1,2);

    head2 = insertFrontSingly(head2,3);
    head2 = insertFrontSingly(head2,4);
    head2 = insertFrontSingly(head2,5);
    head2 = insertFrontSingly(head2,6);

    shuffleMerge(head1,head2);
    getch();
}
