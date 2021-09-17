/* perform following operations on array */
/*  1. Insertion
•	2. Deletion By Index
•	3. Deletion By value
•	4. Searching By Index
•	5. Searching By Value
•	6. Traversing
*/

#include <stdio.h>
#include <stdlib.h>
#define SIZE 30
void insert(int arr[], int s);
void searchByVal(int arr[], int s);
int delByVal(int arr[], int s);
void delByIndex(int arr[], int s);
void searchByIndex(int arr[], int s);
void display(int arr[], int s);

void main()
{
    int c = 0, s, choice; // Variable Declarations
    int arr[SIZE];
    //Array Sizing and Initializing
    printf("Enter How many Elements You want in Array: ");
    scanf("%d", &s);
    for (c = 0; c < s; c++)
    {
        printf("Enter Value for Element %d: ", c);
        scanf("%d", &arr[c]);
    }
    system("cls");

    //printf("\n Enter 1 to Insert at Index\n Enter 2 to Delete by Index\n Enter 3 to search by Value\n Enter 4 to Delete by Value\n Enter 5 to search Value by Index\n Enter 6 to display Array\n Enter 0 to exit\n\tChoice=");
    //scanf("%d",&choice);

    system("cls");
    do
    {

        printf("\n\n\n\n\n\n\t\t\t\t Enter 1 to Insert at Index\n\t\t\t\t Enter 2 to Delete by Index\n\t\t\t\t Enter 3 to search by Value\n\t\t\t\t Enter 4 to Delete by Value\n\t\t\t\t Enter 5 to search Value by Index\n\t\t\t\t Enter 6 to display Array\n\t\t\t\t Enter 0 to exit\n\t\t\t\t\tChoice=");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            insert(arr, s);
            break;
        case 2:
            delByIndex(arr, s);
            break;
        case 3:
            searchByVal(arr, s);
            break;
        case 5:
            searchByIndex(arr, s);
            break;
        case 4:
           s=delByVal(arr, s);
        case 6:
            display(arr, s);
            break;
        }
    } while (choice != 0);
}
void insert(int arr[], int s)
{
    system("cls");
    int loc, val, c = 0, tmp = 0, sh;
    do
    {
        printf("\nEnter the location on which you want to insert value: ");
        scanf("%d", &loc);
        if (loc > s)
        {
            printf("Warning! No Such Location Exist");
            printf("\nEnter a Valid Location");
        }
    } while (loc > s);
    printf("Enter the value you want to insert: ");
    scanf("%d", &val);
    sh = s;
    for (c = 0; c < s; c++)
    {
        if (c == loc)
        {
            tmp = arr[c];
            arr[c] = val;
            s++;
        }
        if (c > loc)
        {
            arr[sh] = arr[sh - 1];
            sh--;
        }
    }
    arr[loc + 1] = tmp;
    printf("\nValue Successfully Inserted at Location %d", loc);
}

void delByIndex(int arr[], int s)
{
    system("cls");
    int i, pos;

    /* Input element position to delete */
    printf("Enter the element position to delete : ");
    scanf("%d", &pos);

    /* Invalid delete position */
    if (pos < 0 || pos > s)
    {
        printf("Invalid position! Please enter position between 1 to %d", s);
    }
    else
    {
        /* Copy next element value to current element */
        for (i = pos - 1; i < s - 1; i++)
        {
            arr[i] = arr[i + 1];
        }

        /* Decrement array size by 1 */
        s--;

        /* Print array after deletion */
        printf("Element is Deleted..!!\n");
        printf("\nElements of array after delete are : ");
        for (i = 0; i < s; i++)
        {
            printf("%d\t", arr[i]);
        }
    }
}
void searchByVal(int arr[], int s)
{
    int data;
    int index;
    printf("Enter the element to search  ");
    scanf("%d", &data);
    int flag = 0;
    for (int i = 0; i < s; i++)
    {
        if (arr[i] == data)
        {
            flag = 1;
            index = i;
        }
    }
    if (flag == 1)
    {
        printf("%d is found at index %d\n", data, index);
    }
    else
    {
        printf("Enter the valid element \n");
    }
}
int delByVal(int arr[], int s)
{
    int data;
    printf("Enter the data to delete\n");
    scanf("%d", &data);
    for (int i = 0; i < s - 2; i++)
    {
        if (arr[i] == data)
        {
            int j = i;
            while (j < s)
            {
                arr[j] = arr[j + 1];// replace from next element
                j++;
            }
            s--; //decreasing the size of array 
        }
    }
    return s; //retturnig the size
}
void searchByIndex(int arr[], int s)
{
    system("cls");
    int loc, c;
    do
    {
        printf("\nEnter the index you want to search: ");
        scanf("%d", &loc);
        if (loc > s)
        {
            system("cls");
            printf("Warning! No Such Location Exist");
            printf("\nEnter a Valid Location");
        }

    } while (loc > s);
    printf("Value at index %d is: %d", loc, arr[loc]);
}
void display(int arr[], int s)
{

    for (int i = 0; i < s; i++)
    {
        printf("%d  ", arr[i]);
    }
}