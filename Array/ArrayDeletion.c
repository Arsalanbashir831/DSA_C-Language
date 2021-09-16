#include <stdio.h>

void display(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d  ", arr[i]);
    }
}

void delete (int arr[], int size, int index)
{

    for (int i = index; i < size - 1; i++)
    {
        arr[i] = arr[i + 1];
    }
   
}

int main()
{
    int arr[] = {1, 2, 3, 5, 7, 9};
    int size = sizeof(arr) / sizeof(int);
    int index = 5;
    if (size <= index)
    {
        printf("no index found\n");
    }
    else
    {
        delete (arr, size, index);
        size -= 1;
    }

    display(arr, size);
    return 0;
}