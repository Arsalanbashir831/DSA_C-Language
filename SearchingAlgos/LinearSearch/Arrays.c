#include <stdio.h>

void display(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d  ", arr[i]);
    }
}
void Search(int arr[],int data){
 int flag=0;
   for (int i = 0; i < size; i++)
    {
        if (data==arr[i])
        {
           flag=1;
        printf("\n%d  is found", arr[i]);
        }

    }
    if (flag==0)
    {
        printf(No data found );
    }
}
int main()
{
    int arr[100] = {1, 2, 3, 5, 7, 9};
    int size = 6;
    display(arr, size);
    printf("Enter the data to search : ");
    int data ;
    scanf("%d",&data);
    Search(arr,data);
    return 0;
}