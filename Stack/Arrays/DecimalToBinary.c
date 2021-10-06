#include <stdio.h>
#include <conio.h>
#define MAX 100
//declaring stack using structure
typedef struct stack
{
    int data[MAX];
    int top;
} stack;
//checking whether the stack is empty or not
int empty(stack *s)
{
    if (s->top == -1)
        return (1);
    return (0);
}
//checking whether the stack is full or not
int full(stack *s)
{
    if (s->top == MAX - 1)
        return (1);
    return (0);
}
//to push the remainder into the stack
void push(stack *s, int x)
{
    s->top = s->top + 1;
    s->data[s->top] = x;
}
//to pop the remainder out from the stack
int pop(stack *s)
{
    int x;
    x = s->data[s->top];
    s->top = s->top - 1;
    return (x);
}

int main()
{
    stack s; //structure member variable
    int num;
    s.top = -1; //top pointer initialized with -1
    printf("Enter a decimal number:");
    scanf("%d", &num);
    while ((num != 0))
    {
        if (!full(&s)) //this condition executes if the function 'full' returns 0
        {
            push(&s, num % 2); //pushing the remainder into the stack using 'push' function
            num = num / 2;
        }
        else
        {
            printf("Stack overflow"); //if stack reaches the MAX value
            exit(0);
        }
    }
    while (!empty(&s))
    {
        num = pop(&s); //poping the remainder out from the stack using 'pop' function
        printf("%d", num);
    }
}
