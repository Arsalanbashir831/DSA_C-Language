#include <stdio.h>
#include <conio.h>
void merge(int arr[], int lowerBound, int mid, int higherBound)
{
    // consider this variable as a pointer 
    // three pointer variables 
    int i, j, k;
    i = lowerBound;  // this points at the lowerbound of my array or u can say the first index
    j = mid + 1; //this points at the the index after the mid point 
    k = lowerBound;// this point also points at the lower bound of the newArray
     int newArray[20]; // dummy array variable
    while (i <= mid && j <= higherBound) // traverse the the i pointer to the mid  and traverse the pointer j to the higher bound
    {
        if (arr[i]  < arr[j]) // if the data of the index where i is pointing is smaller than the data of the index whre j is pointing 
        {
            // basically we r inserting the smallest data first
            // insert this data in to the new Array 
            newArray[k] = arr[i];
            i++; //increment the pointer
             k++; //increment the pointer of the new array
        }
       else
        {
            // if j pointer data is smaller than insert that data in newArray
            newArray[k] = arr[j];
            j++; // increase the j pointer 
            k++; // increase the k pointer in the newArray
        }
    
    }
  // if the i cross the mid and we have remaining elem in other half than 
        while (j <= higherBound)
        {
            //insert all data in j to newArray
            newArray[k] = arr[j];
            j++;
            k++;
        }
    // if the j cross the higherBounds and we have remaining elem in other half than 
      while (i <= mid)
        {
            //insert all element of other half into the newArray
            newArray[k] = arr[i];
            i++;
            k++;
        }
    
    //copying data to newArray
    for (int  z = lowerBound; z <=higherBound; z++)
    {
        arr[z]=newArray[z];
    } 
}
void mergeSort(int arr[],int lowerBound,int higherBound){
    if (lowerBound<higherBound)
    {
        //calculating the mid of array
        int mid=(higherBound+lowerBound)/2;
        //sort the data at the lowerbound to mid
        mergeSort(arr,lowerBound,mid);
        //sort the data tha point after mid till the higherBound
        mergeSort(arr,mid+1,higherBound);
        //merging all the data
        merge(arr,lowerBound,mid,higherBound);
    }
    
}
int main(int argc, char const *argv[])
{
int arr[] = {20, 3, 5, 4, 6, 13, 10, 9, 8, 15, 17};

    int n = sizeof(arr) / sizeof(arr[0]);

    int i = 0;
    printf("\nUnsorted \n");    
    for (int i = 0; i <n; i++)
    {
        printf("%d   ",arr[i]);
    }

    printf("\nSorted \n"); 
    mergeSort(arr,0,n-1);
     for (int i = 0; i <n; i++)
    {
        printf("%d   ",arr[i]);
    }
    return 0;
}
