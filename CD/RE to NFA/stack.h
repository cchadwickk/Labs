#include<iostream>
using namespace std;
#define noOfOps 4
#define noOfStates 20
struct op{
    int table[noOfStates][noOfOps+1];
    int final;
};

struct StackOp
{
    int top,capacity;
    op* array;
};

// Stack Operations
StackOp* createStackOp( int capacity )
{
    StackOp* stack = new StackOp;

    stack->top = -1;
    stack->capacity = capacity;

    stack->array = new op[stack->capacity];

    if (!stack->array)
        return NULL;
    return stack;
}

int isEmptyOp(StackOp* stack)
{
    return stack->top == -1 ;
}

op peekOp(StackOp* stack)
{
    return stack->array[stack->top];
}

op popOp(StackOp* stack)
{
    if (!isEmptyOp(stack))
        return stack->array[stack->top--] ;
    cout<<"Empty stack";
}

void pushOp(StackOp* stack, op ch)
{
    stack->array[++stack->top] = ch;
}
