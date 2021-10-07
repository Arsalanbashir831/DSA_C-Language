#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

struct stack
{
    int size;
    int top;
    char *arr;
};

int stackTop(struct stack *sp)
{
    return sp->arr[sp->top];
}

int isEmpty(struct stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull(struct stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void push(struct stack *ptr, char val)
{
    if (isFull(ptr))
    {
        printf("Stack Overflow! Cannot push %d to the stack\n", val);
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
}

char pop(struct stack *ptr)
{
    if (isEmpty(ptr))
    {
       
        return -1;
    }
    else
    {
        char val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}
int precedence(char ch)
{
    if (ch == '*' || ch == '/')
        return 3;
    else if (ch == '+' || ch == '-')
        return 2;
    else
        return 0;
}

int isOperator(char ch)
{
    if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '(' || ch == ')')
        return 1;
    else
        return 0;
}
char *infixToPostfix(char *infix)
{
    struct stack *sp = (struct stack *)malloc(sizeof(struct stack));
    sp->size = 10;
    sp->top = -1;
    sp->arr = (char *)malloc(sp->size * sizeof(char));
    char *postfix = (char *)malloc((strlen(infix) + 1) * sizeof(char));
    int i = 0; // Track infix traversal
    int j = 0; // Track postfix addition
    while (infix[i] != '\0')
    {
        if (!isOperator(infix[i]))
        {
            postfix[j] = infix[i];
            j++;
            i++;
        }
        
        else if (infix[i] == '(')
        {
            push(sp, infix[i]);
            i++;
        }
        else if (infix[i] == ')')
        {
            char temp;
            while (1)
            {
                temp = pop(sp);
                if (temp == '(')
                {
                    break;
                }
                else
                {
                    postfix[j] = temp;
                    j++;
                }
            }
            i++;
        }

        else if (precedence(infix[i]) > precedence(stackTop(sp)))
        {
            push(sp, infix[i]);
            i++;
        }

        else
        {
            postfix[j] = pop(sp);
            j++;
        }
    }
    while (!isEmpty(sp))
    {
        postfix[j] = pop(sp);
        j++;
    }
    postfix[j] = '\0';
    return postfix;
}

int eval_post(char *postfix)
{
    int a, b, result;
    int temp;
    struct stack *sp = (struct stack *)malloc(sizeof(struct stack));
    sp->size = 10;
    sp->top = -1;
    sp->arr = (char *)malloc(sp->size * sizeof(char));

    for (int i = 0; i < strlen(postfix); i++)
    {
        if (postfix[i] <= '9' && postfix[i] >= '0')
        {
            push(sp, postfix[i] - '0'); 
            /* we saw an operand,push the digit onto stack
             postfix[i] - '0' is used for getting digit rather than ASCII code of digit */
        }
        else
        {
            /* we saw an operator
* pop top element A and next-to-top elemnet B
* from stack and compute B operator A
*/
            a = pop(sp);
            b = pop(sp);
            switch (postfix[i])
            {

            case '+':
                temp = b + a;
                break;
            case '-':
                temp = b - a;
                break;
            case '*':
                temp = b * a;
                break;
            
            case '/':
                temp = b / a;
                break;
            }
            push(sp, temp); // pushing the numbers
        }
    }
    result = pop(sp); //store the evaluated ans in the result
    return result;
}
void brackets(char* infix){
    int i = 0;
    while(infix[i]!='\0')
    {
        if(infix[i]=='(')
            infix[i]=')';
        else if(infix[i]==')')
            infix[i]='(';
        i++;
    }
}
char* reverse(char *exp){

    int size = strlen(exp);
    int j = size-1, i=0;
    char temp[j];
    temp[size]='\0';
    while(i < size)
    {
        temp[j] = exp[i];
        j--;
        i++;
    }
    strcpy(exp,temp);
    return exp;
}
char * InfixtoPrefix(char *exp){
    // reverse string
    reverse(exp);
    //change brackets
    brackets(exp);
    // reverse the postfix expression
    return reverse(infixToPostfix(exp));
    return exp;
}

int main()
{

    char infix[50] = "";
    char *postfix;
    postfix = infixToPostfix(infix);
    printf("Enter the value of the expression\n");
    gets(infix);
    printf("postfix is %s\n", infixToPostfix(infix));
    printf("prefix is %s\n",InfixtoPrefix(infix));
    printf("Evaluated Expression : %d", eval_post(infixToPostfix(infix)));
    getch();
    return 0;
}