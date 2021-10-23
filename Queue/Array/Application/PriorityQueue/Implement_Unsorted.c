#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define SIZE 10
typedef struct PriorityQueueOneArrayUnsorted
{
    struct data //data is priority queue has priority with it (Lower is greater)
    {
        int data;
        int priority;
    } data[SIZE];

    int front;
    int rear;

} priorityQueueOneArrayUnsorted;
int isEmpty(priorityQueueOneArrayUnsorted* queue)
{
    return queue->front == -1 && queue->rear == -1;
}
void initQueue(priorityQueueOneArrayUnsorted* queue)
{
    queue->rear = -1; //here rear will be the index of element with highest priority
    queue->front = -1;
}
void insert(priorityQueueOneArrayUnsorted* queue, int priority, int data)
{
    if (queue->front == SIZE)
    {
        printf("Queue is full");
        return;
    }
    else if (isEmpty(queue))
    {
        queue->front = 0;
        queue->rear = 0;
    }
    else 
    {
        queue->rear++;
            
    }
    queue->data[queue->rear].data = data;
    queue->data[queue->rear].priority = priority;    

   
}

void display(priorityQueueOneArrayUnsorted* queue)
{
    if (isEmpty(queue))
    {
        printf("queue is empty");
        return;
    }

    else
    {
        for (int i = queue->front; i <= queue->rear; i++)
        {
            printf("Data Is  = %d ||| It's Priority is = %d\n",queue->data[i].data,queue->data[i].priority);
        }
        return;
        
    }
    
}

int dequeue(priorityQueueOneArrayUnsorted* queue)
{
    if (isEmpty(queue))
    {
        printf("Empty Queue");
        return -1;
    }
    
    int temp = queue->data[queue->front].data;
    for (int i = queue->front; i <= queue->rear; i++) //removing the highest priority element 
    {
        queue->data[i] = queue->data[i+1];
    }
    queue->rear--;
    int tempPriorityIndex = 0; //starting from first index
    for (int i = 0; i <= queue->rear; i++)
    {

        if(queue->data[i].priority < queue->data[tempPriorityIndex].priority)
        {
            tempPriorityIndex = i; //changing the index
        }
    }
    queue->front = tempPriorityIndex;
    return temp;
    
}


int main() {

    priorityQueueOneArrayUnsorted queue;
    initQueue(&queue);

    insert(&queue,1,2);
    insert(&queue,2,3);
    insert(&queue,1,4);

    display(&queue);

    printf("first dequeued element is = %d\n",dequeue(&queue));
    printf("second dequeued element is = %d\n",dequeue(&queue));
    getch();

    return 0;
}