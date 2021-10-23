#include <stdio.h>
#include "stdlib.h"
struct Queue
{
    int front, rear;
    int size;
    int *arr;
};
void EnqueueF(struct Queue *q, int data)
{
    if ((q->rear + 1) % q->size == q->front)
    {
        printf("overflow");
        return;
    }

    else if (q->front == -1 && q->rear == -1)
    {
        q->front = q->rear = 0;
    }
    else if (q->front == 0&&q->rear==0)
    {

        q->front = q->size - 1;
    }
    else
    {
        q->front--;
    }
   
    q->arr[q->front] = data;
}
void EnqueueR(struct Queue *q,int data)
{
    if ((q->rear + 1) % q->size == q->front)
    {
        printf("overflow");
        return;
    }
     else if (q->front == -1 && q->rear == -1)
    {
        q->front = q->rear = 0;
    }
    else
    {
        q->rear++;
    }
    q->arr[q->rear]=data;

}
int DequeueF(struct Queue*q){
    int data;
       if (q->front == -1 && q->rear == -1)
    {
       printf("Empty");
    }
    else if(q->front==q->rear){
        q->front=q->rear=-1;
    }
    else{
        data=q->arr[q->front];
        q->front++;   
    }
    return data;
}
int DequeueR(struct Queue*q){
int data;
  if (q->front == -1 && q->rear == -1)
    {
       printf("Empty");
    }
     else if(q->front==q->rear){
        q->front=q->rear=-1;
    }
    else{
        data=q->arr[q->rear];
        q->rear--;
    }
    return data;
}
void traverse(struct Queue *ptr)
{
     
    for (int i = ptr->front; ; i++)
    {
        printf("%d ", ptr->arr[i]);
         if (i == ptr->size -1 )
        {
            i = 0;
        }

        if (i == ptr->rear)
        {
            break;
        }
    }

}
int main()
{
    struct Queue *queus = (struct Queue *)malloc(sizeof(struct Queue));
    queus->size = 100;
    queus->front = -1;
    queus->rear = -1;
    queus->arr = (int *)malloc(queus->size * sizeof(int));
     EnqueueF(queus, 8);
    EnqueueR(queus, 2);
    EnqueueR(queus, 3);
    EnqueueR(queus, 1);
    EnqueueF(queus, 9);
    DequeueF(queus);
    DequeueR(queus);
    traverse(queus);   
    return 0;
}