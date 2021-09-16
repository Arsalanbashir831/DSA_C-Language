#include <stdio.h>

void display(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d  ", arr[i]);
    }
}

int main()
{

    int arr[100] = {1, 2, 3, 5, 7, 9};
    int size = 6;
    display(arr, size);
    return 0;
}