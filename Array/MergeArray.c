#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
struct Array
{
    int *arr1;
    int *arr2;
    int *resultArray;
    int size;
};
int main(int argc, char const *argv[])
{
    struct Array *arr = (struct Array *)malloc(sizeof(struct Array));
    int arr1Size = arr->size;
    int arr2Size = arr->size;
    int index = 0;
    // initializing the size of the arrays
    arr->arr1 = (int *)malloc(arr->size * sizeof(int ));
    arr->arr2 = (int *)malloc(arr->size * sizeof(int ));
    // the size of the resultant array would be the sum of the size of arr1 and arr2
    arr->resultArray = (int *)malloc(arr->arr1[arr->size] + arr->arr2[arr->size] * sizeof(int ));

    printf("Enter the size of the 1st array : ");
    scanf("%d", &arr1Size);
    printf("Enter the size of the 2nd array : ");
    scanf("%d", &arr2Size);
    printf("\n ====Enter the elements in 1st array====\n ");
    for (int i = 0; i < arr1Size; i++)
    {
        scanf("%d", &arr->arr1[i]);
    }
    printf("\n ====Enter the elements in 2nd array====\n ");
    for (int i = 0; i < arr2Size; i++)
    {
        scanf("%d", &arr->arr2[i]);
    }
    int resultSize = arr1Size + arr2Size;
    // copy the elements of   array 1 and paste to resultant array
    for (int i = 0; i < arr1Size; i++)
    {
        arr->resultArray[index] = arr->arr1[i];
        index++;
    }
    // copy the elements of   array 2 and paste to resultant array
    for (int i = 0; i < arr2Size; i++)
    {
        arr->resultArray[index] = arr->arr2[i];
        index++;
    }

    // printing the resultant array
    printf("\n ==== Unsorted resultant Array ======\n");
    for (int i = 0; i < resultSize; i++)
    {
        printf("%d   ", arr->resultArray[i]);
    }
    printf("\n ==== Sorted resultant Array ======\n");
    int temp;
    //sorting the resultant array
    for (int i = 0; i < resultSize; i++)
    {
        for (int j = 0; j < resultSize; j++)
        {
            if (arr->resultArray[i] < arr->resultArray[j])
            {
                temp = arr->resultArray[i];
                arr->resultArray[i] = arr->resultArray[j];
                arr->resultArray[j] = temp;
            }
        }
    }
    //printing the array
    for (int i = 0; i < resultSize; i++)
    {
        printf("%d   ", arr->resultArray[i]);
    }
    return 0;
}
