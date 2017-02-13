#include <string.h>
#include <stdlib.h>

struct Stack
{
    int top,capacity;
    int* array;
};

// Stack Operations
Stack* createStack( int capacity )
{
    Stack* stack = new Stack;

    stack->top = -1;
    stack->capacity = capacity;

    stack->array = new int[stack->capacity];

    if (!stack->array)
        return NULL;
    return stack;
}

int isEmpty(Stack* stack)
{
    return stack->top == -1 ;
}

char peek(Stack* stack)
{
    return stack->array[stack->top];
}

char pop(struct Stack* stack)
{
    if (!isEmpty(stack))
        return stack->array[stack->top--] ;
    return '$';
}

void push(Stack* stack, char ch)
{
    stack->array[++stack->top] = ch;
}

int isOperand(char ch)
{
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch=='*');
}

int Prec(char ch)
{
    if(ch=='.')
        return 1;
    else if(ch=='+')
        return 2;
    else if(ch=='*')
        return 3;
    return -1;
}

char* inToPost(char* exp)
{
    int i, k;

    Stack* stack = createStack(strlen(exp));
    if(!stack)      // CHECK IF STACK CREATED
        return 0;

    for (i = 0, k = -1; exp[i]; ++i)
    {
        if (isOperand(exp[i]))      //IF OPERAND ADD TO OUTPUT
            exp[++k] = exp[i];

        else if (exp[i] == '(')
            push(stack, exp[i]);

        else if (exp[i] == ')')     //POP TILL '('
        {
            while (!isEmpty(stack) && peek(stack) != '(')
                exp[++k] = pop(stack);
            if (!isEmpty(stack) && peek(stack) != '(')
                return 0;           // '(' NOT FOUND
            else
                pop(stack);
        }
        else                        //OPERATOR
        {
            while (!isEmpty(stack) && Prec(exp[i]) <= Prec(peek(stack)))
                exp[++k] = pop(stack);
            push(stack, exp[i]);
        }

    }

    while (!isEmpty(stack))         //POP ANY REMAINING OPERATORS
        exp[++k] = pop(stack );

    exp[++k] = '\0';
    return exp;
}
