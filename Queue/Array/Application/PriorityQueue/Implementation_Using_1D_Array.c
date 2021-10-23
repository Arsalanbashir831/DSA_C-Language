#include <stdio.h>
#include <stdlib.h>
struct Queue
{
    int *Q;
    int *Pri;
    int r, f, size;
};
struct Queue *ptr;
int sort()
{
    // sorting the data and priority array on the basis of priority
    int tempData = ptr->Q[ptr->f];
    int tempPriority = ptr->Pri[ptr->f];

    for (int i = ptr->f; i <= ptr->r; i++)
    {
        for (int j = ptr->f; j < ptr->r; j++)
        {
            if (ptr->Pri[j] < ptr->Pri[j + 1])
            {
                tempData = ptr->Q[j];
                tempPriority = ptr->Pri[j];
                ptr->Q[j] = ptr->Q[j + 1];
                ptr->Pri[j] = ptr->Pri[j + 1];
                ptr->Q[j + 1] = tempData;
                ptr->Pri[j + 1] = tempPriority;
            }
        }
    }
}
void Enque(int val, int priority)
{
    if (ptr->f == 0 && ptr->r == ptr->size - 1)
    {
        printf("Queue is full");
    }

    else if (ptr->f == -1 && ptr->r == -1)
    {
        ptr->r = ptr->f = 0;
    }

    else
    {
        ptr->r++;
    }
    ptr->Q[ptr->r] = val;
    ptr->Pri[ptr->r] = priority;
    sort();
}

int Deque()
{

    if (ptr->f == -1 && ptr->r == -1)
    {
        printf("is Empty");
    }
    else if (ptr->f == ptr->r)
    {
        ptr->f = ptr->r = -1;
    }
    else
    {
        printf("Delete data = %d  priority = %d\n", ptr->Q[ptr->f], ptr->Pri[ptr->f]);
        for (int i = ptr->f; i <= ptr->r; i++)
        {
            // shifting to empty elements
            ptr->Q[i] = ptr->Q[i + 1];
            ptr->Pri[i] = ptr->Pri[i + 1];
        }
        // decreasing size by decrementing the rare
        ptr->r--;
    }
}
void Traversal()
{
    // traversing using loop simple
    for (int i = ptr->f; i <= ptr->r; i++)
    {
        printf("Data = %d    priority = %d \n", ptr->Q[i], ptr->Pri[i]);
    }
}

int main()
{
    ptr = (struct Queue *)malloc(sizeof(struct Queue));
    ptr->f = ptr->r = -1;
    ptr->size = 100;
    ptr->Q = (int *)malloc(ptr->size * sizeof(int));
    ptr->Pri = (int *)malloc(ptr->size * sizeof(int));
    int opt, data, priority;
    printf("Choose the option\n");
    while (1)
    {
        printf("\n1 - Insert the data\n2 - Delete the data\n3 - Display\n4 - exit(press 0)\n");
        scanf("%d", &opt);
        if (opt == 0)
        {
            printf("\n===== Thank you for using this program ======\n");
            break;
        }
        if (opt == 1)
        {
            printf("Enter the data  : ");
            scanf("%d", &data);
            printf("Enter the priority : ");
            scanf("%d", &priority);
            printf("Data : %d \t priority : %d inserted \n", data, priority);
            Enque(data, priority);
            printf("\n");
        }

        if (opt == 2)
        {
            Deque();
            printf("\n");
        }
        if (opt == 3)
        {
            printf("\n");
            Traversal();
        }
    }
    return 0;
}
