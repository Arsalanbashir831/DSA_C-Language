#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define SIZE 10
typedef struct PriorityQueueTwoArray
{
    int data[SIZE][SIZE]; //first d is for priority and other one will act like a simple linear queue :) (You can use circular queue in this too)
    int front[SIZE];
    int rear[SIZE];
} priorityQueueTwoArray;

void initQueue(priorityQueueTwoArray *queue)
{
    for (int i = 0; i < SIZE; i++)
    {
        queue->front[i] = -1;
        queue->rear[i] = -1;
        for (int j = 0; j < SIZE; j++)
        {
            queue->data[i][j] = -999;
        }
        
    }
    
}
void enqueue(priorityQueueTwoArray *queue, int priority, int data)
{
    int rear;
    priority = priority - 1; //index starts from 0 and priority from 1
    if (queue->rear[priority] >= SIZE)
    {
        printf("Queue is Full ");
        return;
    }
    else if (queue->front[priority] == -1 && queue->rear[priority] == -1)
    {
        queue->front[priority] = 0;
        queue->rear[priority] = 0;
        rear = 0;
    }
    else
        rear = ++queue->rear[priority];

    queue->data[priority][rear] = data; //rear is also an array
    
}

int dequeue(priorityQueueTwoArray *queue, int priority)
{
    priority = priority - 1;
    int front;
    if (queue->front[priority] == -1 && queue->rear[priority] == -1)
    {
        printf("Queue is empty");
        return -1;
    }
    else if (queue->front[priority] == queue->rear[priority])
    {
        front = queue->front[priority];
        queue->front[priority] == -1;
        queue->rear[priority] == -1;
        return queue->data[priority][front];
    }
    front = queue->front[priority]++;

    return queue->data[priority][front];
}

void display(priorityQueueTwoArray *queue)
{
    for (int priority = 0; priority < SIZE; priority++)
    {
        printf("For PRIORITY #%d\n", priority + 1); //index starts from 0 Priority doesn't, suck it
        if (queue->front[priority] == -1 && queue->rear[priority] == -1)
        {
            printf("Priority #%d is empty\n",priority+1);
            continue;
        }
        for (int front = queue->front[priority]; front <= queue->rear[priority]; front++)
        {
            if (queue->data[priority][front] == -999)
            {
                break;
            }

            else
            {
                printf("Element is = %d\n",queue->data[priority][front]);
            }
        }
        printf("----------------------------\n");
    }
}
int main()
{
    priorityQueueTwoArray queue;
    initQueue(&queue);

    enqueue(&queue,1,1);
    enqueue(&queue,1,5);
    enqueue(&queue,2,13);
    enqueue(&queue,2,17);
    display(&queue);

    printf("\n\nHighest Priority Element Dequeued is = %d\n",dequeue(&queue,1));
    getch();
    return 0;
}