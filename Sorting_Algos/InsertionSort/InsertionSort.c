#include<stdio.h>

int main()
{
   int arr[5]={4,2,1,7,8};
    printf("Unsorted Array\n");
    printf("[");
    for (int i = 0; i < 5; i++)
    {
        printf(" %d ",arr[i]);
    }
    printf("]");
    printf("\nSorted by Insertion Sort\n");
    for (int i = 0; i <= 5; i++)
    {
        int tem=arr[i];// the element which is to be shift
        int j=i-1;// moving to previous index of current element for comparing
        while (tem<=arr[j]&&(j>=0)) // shifting the elements
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=tem;
    }
       printf("[");
    for (int i = 0; i < 5; i++)
    {
        printf(" %d ",arr[i]);
    }
    printf("]");  
return 0;

}