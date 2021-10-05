#include <stdio.h>
#include <stdlib.h>

struct Stack
{
    int size;
    int top;
    int *arr;
};
struct Stack *str;
void display(){
    for (int i = 0; i <= str->top; i++)
    {
        
             printf("%d  ",str->arr[i]);
    }
    
}
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
int main()
{
    str = (struct Stack *) malloc(sizeof(struct Stack));
    str->size = 5;
    str->top = -1;
    str->arr = (int *)malloc(str->size * sizeof(int));
    push(4);
    push(1);
    push(2);
    display();
    
    // str->arr[0]=4;
    // str->top++;
    // str->arr[1]=4;
    // str->top++;
    // str->arr[2]=4;
    // str->top++;
    // str->arr[3]=4;
    // str->top++;

    // if (isEmpty())
    // {
    //     printf("Stack is empty");
    // }
    // else if (isFull())
    // {
    //     printf("Stack is Full");
    // }
    // else
    // {
    //     printf("Stack is not empty");
    // }

    return 0;
}