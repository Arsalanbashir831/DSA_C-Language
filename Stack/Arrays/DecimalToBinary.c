#include <stdio.h>
#include <stdlib.h>

struct Stack
{
    int size;
    int top;
    int *arr;
};

void display(struct Stack *str){
    for (int i = 0; i <= str->top; i++)
    {
        
             printf("%d  ",str->arr[i]);
    }
    
}
int isEmpty(struct Stack *str)
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
int isFull(struct Stack *str)
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
void push(struct Stack *str,int data){
    if (isFull(str))
    {
        printf("Stack is full");
    }
    else{
        str->top++;
        str->arr[str->top]=data;
    }
}
int pop(struct Stack *str){
    if (isEmpty(str))
    {
        printf("Stack is Empty");
    }
    else{
        int val=str->arr[str->top];
        str->top=str->top-1;
        return val;
    }
    
}
void decimalToBinary(int value,struct Stack *str){
    str->top=-1;
    int rem=0;
    while (value!=0)
    {
        rem=value%2;
        push(str,rem);
        value/2;
      
    }

    while(str->top!=-1)
   {
       printf("%d",pop(str));
   }
   
}
int main()
{
  struct Stack* str = (struct Stack *) malloc(sizeof(struct Stack));
    str->size = 100;
    str->top = -1;
    str->arr=(int *)malloc(str->size*sizeof(int));
   decimalToBinary(10,str);
   
    
    return 0;
}