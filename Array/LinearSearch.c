#include <stdio.h>

void linearSearch(int arr[], int size, int element)
{
    for (int i = 0; i < size; i++)
    {
        if (element == arr[i])
        {
            printf("%d is found at %d", element, i);
        }
    }
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int size = sizeof(arr) / sizeof(int);
    linearSearch(arr, size, 4);
    return 0;
}