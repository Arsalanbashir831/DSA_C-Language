#include<stdio.h>
#include<conio.h>
#define size 10
void swap(int *a,int *b){
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}

int partition(int arr[],int lowerBound,int higherBound){
    int pivot=arr[lowerBound];//pivot is my rightest element
    int start=lowerBound; // this start var will point at the 1st index of my array
    int end=higherBound;// this end var will point at the last index of my array
    while (start<=end) // my swaping will be iterated till my start pointer is smaller or equal to the end
    {
        if (arr[start]>=pivot) 
        {
            /*
            if my start pointer is less than the pivot than move the start pointer at the next index.
            otherwise the start pointer will stop at that point.
            */
            start++;
        }
        // after checking the start pointer we will now check at the end pointer
        if (arr[end]<pivot)
        {
            /*
            if end pointer is greater than the pivot than move the end pointer at the backward direction by one index
            other wise end pointer stop at that index
                */
            end--;
        }
        if (start<end)
        {
            //if my start pointer < end pointer than 
            // do swaping
            swap(&arr[start],&arr[end]); 
        }
        
    }
    // if start>end pointer than do swap with lowerbound (which is our pivot )to the end pointer 
    swap(&arr[lowerBound],&arr[end]);

    return end;
}

void QuickSort(int arr[],int lowerBound,int higherBound){
    
    if (lowerBound<higherBound)
    {
        //set the pivot at the center where all data at the left will have the data lower tha pivot and higher at the right side of the pivot
        int pivot=partition(arr,lowerBound,higherBound);
        // do sort at the first half.
        //we are not involving the pivot element in sorting because we already sort that data at the partition function.
        //that is y i write pivot-1 means data right before pivot element
        QuickSort(arr,lowerBound,pivot-1);
        //do sort at the other half.
          //we are not involving the pivot element in sorting because we already sort that data at the partition function.
        //that is y i write pivot+1 means data right after pivot element 
        QuickSort(arr,pivot+1,higherBound);

    }
}

int main()
{
   
int arr[] = {20, 3, 5, 4, 6, 13, 10, 9, 8, 15, 17};
    printf("\nUnsorted \n");    
    for (int i = 0; i <size; i++)
    {
        printf("%d   ",arr[i]);
    }

    printf("\nSorted \n"); 
     QuickSort(arr,0,size-1);   
    for (int i = 0; i <size; i++)
    {
        printf("%d   ",arr[i]);
    }
    
    return 0;
}
