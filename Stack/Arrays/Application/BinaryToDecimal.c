#include <stdio.h>
#include <stdlib.h>
#include <math.h>
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
int power(int number, int power)
{
    int num=number;
    for (int i = 1; i < power; i++)
    {
        number = number * num;
    }

    return number;
    
}
int binaryToDecimal(char binary[])
{
    str->top = -1;
    int base = 0;
    int result  = 0;
    for (int i = 0; binary[i] != '\0'; i++)
    {
        if (binary[i] != '0' && binary[i] != '1')
        {
            printf("Illegal Binary Expression");
            return -1;
        }
        
        push(binary[i] - '0');
   
    }
    while (!isEmpty(str))
    {
        result = result + (power(2,base) * pop());
        base++;
    }

    return result;
       
    
}

int main()
{
     str = (struct Stack *) malloc(sizeof(struct Stack));
    str->size = 100;
    str->top = -1;
    str->arr = (int *)malloc(str->size * sizeof(int));
   char binary[50];
    printf("Enter the Binary Number");
    gets(binary);
    printf("Decimal Result is = %d",binaryToDecimal(binary));
    return 0;
}
