#include <stdio.h>
#include <stdlib.h>
#define Size 100;
struct queus
{
    int rear;
    int front;
    char *arr;
    int maxSize;
};
struct queus *create(int size)
{
    struct queus *queus = (struct queus *)malloc(sizeof(struct queus));
    queus->maxSize = size;
    queus->front = -1;
    queus->rear = -1;
    queus->arr = (char *)malloc(queus->maxSize * sizeof(char));
    return queus;
}
void enque(struct queus *queus, char value)
{

    {
        if (queus->rear == queus->maxSize - 1)
        {
            printf("Size is full");
        }
        else
        {
            queus->rear++;
            queus->arr[queus->rear] = value;
        }
    }
}
char deque(struct queus *ptr)
{
    char temp;
    if (ptr->front == ptr->rear)
    {
        printf("Empty queue");
    }
    else
    {
        ptr->front++;
        ptr->arr[ptr->front] = temp;
    }
    return temp;
}
void traverse(struct queus *ptr)
{
    for (int i = ptr->front + 1; i <= ptr->rear; i++)
    {
        printf("%c  ", ptr->arr[i]);
    }
}
int main()
{
    int size = Size;
    struct queus *queus = create(size);
    enque(queus, 'A');
    enque(queus, 'B');
    enque(queus, 'C');
    deque(queus);
    traverse(queus);

    return 0;
}