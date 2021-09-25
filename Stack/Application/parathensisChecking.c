#include <stdio.h>
#include <stdlib.h>

struct Stack
{
    int size;
    int top;
    char *arr;
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
void push(char data){
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
    str->size = 100;
    str->top = -1;
    str->arr = (char *)malloc(str->size * sizeof(char));
    printf("Enter the Expression");
    gets(str->arr);
    for (int i = 0; i < str->size; i++)
    {
        if (str->arr[i]=='(')
        {
            push('(');
        }
        else if (str->arr[i]==')')
        {
            pop();
        }
    }
    
if (isEmpty())
{
    printf("brackets are balance");
}
else
{
    printf("Unbalanced");
}

    return 0;
}