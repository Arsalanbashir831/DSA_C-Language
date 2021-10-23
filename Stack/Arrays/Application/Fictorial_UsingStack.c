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
      return 0;
    }
    else{
        int val=str->arr[str->top];
        str->top=str->top-1;
        return val;
    }
    
}
void fictorial(int num){
    while (num!=0)
    {
       push(num);
       num--;    
    }
    int result=1;
  for (int i = str->top; i >-1; i--)
  {
    result=result*pop();
  }
  printf("%d",result);
}
int main()
{
    str = (struct Stack *) malloc(sizeof(struct Stack));
    str->size = 100;
    str->top = -1;
    str->arr = (int *)malloc(str->size * sizeof(int));
    int num;
    printf("Enter the number ");
    scanf("%d",&num);
    printf("Fictorial is : ");
    fictorial(num);

    return 0;
}