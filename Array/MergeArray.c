#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
struct Array{
    int *arr1;
    int *arr2;
    int *resultArray;
    int size;
};
int main(int argc, char const *argv[])
{
     struct Array * arr = (struct Array *)malloc(sizeof(struct Array));
     int arr1Size=arr->size;
     int arr2Size=arr->size;
  
     int index=0;
     arr->arr1=(int *)malloc(arr->size*sizeof(int*));
     arr->arr2=(int *)malloc(arr->size*sizeof(int*));
     arr->resultArray=(int *)malloc(arr->arr1[arr->size]+arr->arr2[arr->size] *sizeof(int*));

    printf("Enter the size of the 1st array : ");
    scanf("%d",&arr1Size);
    printf("Enter the size of the 2nd array : ");
    scanf("%d",&arr2Size);
    printf("\n ====Enter the elements in 1st array====\n ");
    for (int i = 0; i < arr1Size; i++)
    {
        scanf("%d",&arr->arr1[i]);
    }
    printf("\n ====Enter the elements in 2nd array====\n ");
    for (int i = 0; i < arr2Size; i++)
    {
        scanf("%d",&arr->arr2[i]);
    }
        int resultSize=arr1Size+arr2Size;
        for (int i = 0; i < arr1Size; i++)
    {
        arr->resultArray[index]=arr->arr1[i];
        index++;
    }
    
    for (int i = 0; i < arr2Size; i++)
    {
        arr->resultArray[index]=arr->arr2[i];
        index++;
    }    

    
 printf("\n ==== resultant Array ======\n");
    for (int i = 0; i < resultSize; i++)
    {
        printf("%d   ",arr->resultArray[i]);
    }
    
    return 0;
}
