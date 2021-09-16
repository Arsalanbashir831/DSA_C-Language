#include <stdio.h>

void display(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d  ", arr[i]);
    }
}
int IndexInsertion(int arr[], int size, int element, int index, int capacity)
{
    if (size >= capacity)
    {
        return -1;
    }
    for (int i = size-1; i >= index; i--)
    {
        arr[i+1]=arr[i];
    }
    arr[index]=element; 
    return 1;

    
}
int main()
{

    int arr[100] = {1, 2, 3, 5, 7, 9};
    int size = 6;
    int element = 45, index = 3;
    display(arr, size);
    IndexInsertion(arr, size, element, index, 100);
    size++;
    printf("\n");
    display(arr, size);
    return 0;
}