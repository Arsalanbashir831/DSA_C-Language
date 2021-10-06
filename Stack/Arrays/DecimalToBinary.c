#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
struct stack
{
    int size;
    int *arr;
    int top;
};
struct stack *ptr;
int push(int data)
{
    if (ptr->top == ptr->size - 1)
    {
        return 0;
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = data;
    }
}
int pop(){
    int val;
    if (ptr->top==-1)
    {
        return 0;
    }
    else
    {
        val=ptr->arr[ptr->top];
        ptr->top--;
    }

}
int decimalToBinary(int data){
    int rem;
    while (data !=0)
    {
        rem = data%2;
        push(data);
        data/2;
    }
    int result;
    while (ptr->top!=-1)
    {
       result=pop();
    }
    return result;
}
int main()
{
 ptr = (struct stack *) malloc(sizeof(struct stack));
    ptr->size = 100;
    ptr->top = -1;
    ptr->arr = (int *)malloc(ptr->size * sizeof(int));
int integer=10;
decimalToBinary(integer);
int i=0;
while (i<=ptr->arr[ptr->top])
{
    printf("%d ",ptr->arr[i]);
    i++;
}

    return 0;
}
