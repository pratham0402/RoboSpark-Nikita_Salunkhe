#include<stdio.h>

int push(int top, int *stack);
int pop(int top, int *stack);

int main(){
    int stack[100];
    int top = -1;
    char given[] = "((((((((())))))))))";

    

    for (int i=0; i<100; i++)
    {
        if (given[i] == '('){
            top = push(top,stack);
        }
        else if (given[i] == ')')
        {
            top = pop(top,stack);
        }
        else
        {
            break;
        }
        
    }
    
    if (top == -1)
    {
        printf("the brackets are balanced");
    }
    else if (top < -1)
    {
        printf("the brackets on left-side are more");
    }
    else
    {
        printf("the brackets on right-side are more");
    }
    
    
}

int push(int top, int *stack)
{
    if (top == -1)
    {
        printf("no element in stack");
    }
    else
    {
        ++top;
        stack[top] = 1;
    }
    return top;
    
}

int pop(int top, int *stack)
{
    if (top == -1)
    {
        printf("no element in stack");
    }
    return --top;
}