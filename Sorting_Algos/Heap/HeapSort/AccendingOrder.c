#include <stdio.h>
#include <conio.h>
#include <math.h>

// swaping function
void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
 
}
// creating max heap
int heapify(int index, int arr[], int size)
{
    // consider each variable as a pointer
    int largest = index;                                   // the largest variable points at the index of the last parent node
    int leftChild = index * 2 + 1;                         // the left child will point at the index of left child of the last parent node
    int rightChild = index * 2 + 2;                        // the right child will point at the index of right child of the last parent node
    int flag = 0;                                          // it is toggle variable
    if (leftChild < size && arr[leftChild] > arr[largest]) // if the left child is greater than their parent
    {
        flag = 1;            // update the flag to 1
        largest = leftChild; // the largest will point at the index of left child
    }
    if (rightChild < size && arr[rightChild] > arr[largest]) // if the right child is greater than their parent
    {
        flag = 1;             // update the flag to 1
        largest = rightChild; // the largest will point at the index of the right child
    }
    // if the flag ==1 so do swapping  flag will be 1 if any of the above condition is true otherwise the flag value will not be change
    // this will remain to 0
    if (flag == 1)
    {
        // swaping to the index of parent or we can say at the last parent node to largest pointer which was pointing to that respective child
        swap(&arr[index], &arr[largest]);
        // recursive calling to move at the other nodes to for swaping for more understanding read the build heapify function
        heapify(largest, arr, size);
    }
}
void buildHeap(int arr[], int n)
{
    // the start index will be the last parent node
    int startIdx = (n / 2) - 1;
    // going to last parent node to top parent node
    for (int i = startIdx; i >= 0; i--)
    {
        // calling heapify function
        heapify(i, arr, n);
    }
}
void insertAtHeapify(int data, int arr[], int size)
{
    size = size + 1;  // increasing the size as we are inserting the new data in array
    arr[size] = data; // store the new  data at the last index
    int i = size;     // this variable will points at the last index element of array
    while (i > 0)     // traversing the loop till it reach to 1st index
    {
        int parent = floor(i / 2); // reaching to the parent node NOTE : this is a formula to catch parent node
        if (arr[parent] < arr[i])  // if the new data is greater than the parent node
        {
            // swap new data with parent node
            swap(&arr[parent], &arr[i]);
            // update the variable i to parent which represent the parent of swaped new data node
            i = parent;
        }
        else
        {
            return;
        }
    }
}

void heapSort(int arr[], int size)
{
   for (int i = size - 1; i >= 0; i--) {
      swap(&arr[0], &arr[i]);
      heapify(0, arr, i);
    }
}

int main(int argc, char const *argv[])
{

    int arr[] = {1, 3, 5, 4, 6, 13, 10, 9, 8, 15, 17};

    int n = sizeof(arr) / sizeof(arr[0]);
    int i = 0;
    printf("\nUnsorted \n");
    insertAtHeapify(99, arr, n);
    for (int i = 0; i <n; i++)
    {
        printf(" %d ", arr[i]);
    }
    printf("\n");
    buildHeap(arr, n);
    printf("\nSorted Array \n");
    heapSort(arr,n);
    for (int i = 0; i < n; i++)
    {
        printf(" %d ", arr[i]);
    }
    getch();
    return 0;
}