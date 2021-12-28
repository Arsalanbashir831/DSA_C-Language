#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void taversal(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("%d   ", ptr->data);
        ptr = ptr->next;
    }
}
struct Node *middle(struct Node *start, struct Node *last)
{
    if (start == NULL)
        return NULL;

    struct Node *slow = start;
    struct Node *fast = start->next;
    while (fast != last)
    {
        fast = fast->next;
        if (fast != last)
        {
            slow = slow->next;
            fast = fast->next;
        }
    }

    return slow;
}

// Function for implementing the Binary
// Search on linked list
struct Node *binarySearch(struct Node *head, int value)
{
    struct Node *start = head;
    struct Node *last = NULL;

    do
    {
        // Find middle
        struct Node *mid = middle(start, last);

        // If middle is empty
        if (mid == NULL){
                return NULL;
        }
          

        // If value is present at middle
        if (mid->data == value)
        {
            printf(" \n%d is found ", value);
            return mid;
        }

        // If value is more than mid
        else if (mid->data < value)
            start = mid->next;

        // If the value is less than mid.
        else
            last = mid;

    } while (last == NULL || last != start);
    // value not present
    return NULL;
}

int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;

    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));

    head->data = 4;
    head->next = second;

    second->data = 11;
    second->next = third;

    third->data = 78;
    third->next = fourth;

    fourth->data = 90;
    fourth->next = NULL;

    taversal(head);
    printf("Enter the data to search : ");
    int data;
    scanf("%d", &data);
    head = binarySearch(head, data);
    return 0;
}