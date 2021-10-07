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
void decimalToBinary(int num){
    int rem;
     str = (struct Stack *) malloc(sizeof(struct Stack));
    str->size = 100;
    str->top = -1;
    str->arr = (int *)malloc(str->size * sizeof(int));
    
    while (num!=0)
    {
        rem=num%2;
        push(rem);
        num = num/2;
       
    }
     while (str->top!=-1)
   {
       printf("%d",pop());
   }
  
}
int main()
{
    str = (struct Stack *) malloc(sizeof(struct Stack));
    str->size = 100;
    str->top = -1;
    str->arr = (int *)malloc(str->size * sizeof(int));
    int num;
    printf("Enter the decimal number");
    scanf("%d",&num);
    printf("Binary is : ");
    decimalToBinary(num);
 

  
   

    return 0;
}