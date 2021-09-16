#include <stdio.h>

void display(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d  ", arr[i]);
    }
}

void deleteByValue(int arr[], int size, int data)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == data)
        {
            int j = i;
            while (j <= size)
            {
                arr[j] = arr[j + 1];
                j++;
            }
        }
    }
}

int main()
{
    int arr[] = {1, 2, 3, 5, 7, 9};
    int size = sizeof(arr) / sizeof(int);
    int data = 5;
    deleteByValue(arr, size, data);
    size--;
    display(arr, size);
    return 0;
}