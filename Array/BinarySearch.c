#include <stdio.h>

void binarySearch(int arr[], int element, int size)
{
    int low = 0;
    int high = size - 1;
    int mid;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (element == arr[mid])
        {
            printf("%d is found at index %d", element, mid);
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
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int size = sizeof(arr) / sizeof(int);
    int element = 6;
    binarySearch(arr, element, size);
    return 0;
}