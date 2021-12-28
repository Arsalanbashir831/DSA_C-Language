#include<stdio.h>
int swap(int *a,int *b){
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
  
}
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
    printf("\nSorting By Bubble Sort\n");
    for (int i = 0; i < 5; i++)
    {
       for (int j = 0; j < 5-i; j++)
       {
           if (arr[j]>arr[j+1])
           {
               swap(&arr[j],&arr[j+1]);
           }      
       }
    }
     printf("[");
    for (int i = 0; i < 5; i++)
    {
        printf(" %d ",arr[i]);
    }
    printf("]");
    
return 0;

}