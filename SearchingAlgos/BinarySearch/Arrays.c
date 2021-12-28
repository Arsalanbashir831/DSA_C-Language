#include <stdio.h>
void display(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d  ", arr[i]);
    }
}
int Search(int arr[], int size, int element)
{
    int low, mid, high;
    low = 0;
    high = size - 1;
    // Keep searching until low <= high
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (arr[mid] == element)
        {
            printf("%d founded",element);
            return mid;
        }
        if (arr[mid] < element)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return -1;
}

int main()
{
    int arr[100] = {1, 2, 3, 5, 7, 9};
    int size = 6;
    display(arr, size);
    printf("Enter the data to search : ");
    int data;
    scanf("%d", &data);
    Search(arr,size,data);
    return 0;
}