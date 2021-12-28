#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
struct Node
{
    int data;
    struct Node *next;
};
struct AdjList
{
    struct Node *head;
};
struct AdjList *arrAdjList[5] = {0};
void addNode(int source, int destination)
{
    struct Node *dest, *temp, *src;
    if (arrAdjList[source]->head == NULL)
    {
        src = (struct Node *)malloc(sizeof(struct Node));
        src->data = source;
        src->next = NULL;
        arrAdjList[source]->head = src;
    }

    dest = (struct Node *)malloc(sizeof(struct Node));
    dest->data = destination;
    dest->next = NULL;
    temp = arrAdjList[source]->head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = dest;
}
void PrintList()
{
    for (int i = 0; i < 5; i++)
    {
        struct Node *p = arrAdjList[i]->head;
        printf("Adj List for vertex %d  \n", i);
        while (p)
        {
            printf("%d  ", p->data);
            p = p->next;
        }
        printf("\n");
    }
}

void PrintListOnly(int v)
{
    for (int i = 0; i < 5; i++)
    {
        struct Node *p = arrAdjList[i]->head;
        if (v == arrAdjList[i]->head->data)
        {
            printf("Adj List for vertex %d  \n", i);
            while (p)
            {
                printf("%d  ", p->data);
                p = p->next;
            }
        }

    }
}
void CreateNode(int size)
{
    for (int i = 0; i < size; i++)
    {
        arrAdjList[i] = (struct AdjList *)malloc(sizeof(struct AdjList));
        arrAdjList[i]->head = NULL;
    }
}
int main(int argc, char const *argv[])
{
    CreateNode(5);
    addNode(0, 1);
    addNode(0, 2);
    addNode(1, 6);
    addNode(2, 33);
    addNode(3, 12);
    addNode(4, 11);
    PrintList();
    printf("\n====User input====\n");
    PrintListOnly(3);
  
    return 0;
}