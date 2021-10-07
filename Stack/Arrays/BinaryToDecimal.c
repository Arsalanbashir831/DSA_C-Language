#include <stdio.h>
#include <stdlib.h>

struct Stack
{
    int size;
    int top;
    int *arr;
};
struct Stack *str;

int isEmpty()
{
    if (str->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int isFull()
{
    if (str->top == str->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void push(int data){
    if (isFull())
    {
        printf("Stack is full");
        
    }
    else{
        str->top++;
        str->arr[str->top]=data;
    }
}
int pop(){
    if (isEmpty())
    {
        printf("Stack is Empty");
    }
    else{
        int val=str->arr[str->top];
        str->top=str->top-1;
        return val;
    }
    
}
void BinaryToDecimal(int num){
    while (!isEmpty())
    {
        
    }
    
}
int main()
{
     str = (struct Stack *) malloc(sizeof(struct Stack));
    str->size = 100;
    str->top = -1;
    str->arr = (int *)malloc(str->size * sizeof(int));
    return 0;
}
