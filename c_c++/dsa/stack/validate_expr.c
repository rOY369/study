#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPR_LENTGH 100

struct Stack
{
    int top;
    unsigned int capacity;
    char *arr;
};

struct Stack *create_stack(unsigned int capacity)
{

    struct Stack *stack = (struct Stack *)malloc(sizeof(struct Stack));

    stack->capacity = capacity;
    stack->top = -1;
    stack->arr = (char *)malloc(sizeof(char) * capacity);

    return stack;
}

int is_empty(struct Stack *stack)
{
    return (stack->top == -1);
}

int is_full(struct Stack *stack)
{
    return ((stack->top + 1) == stack->capacity);
}

void push(struct Stack *stack, int e)
{
    if (is_full(stack))
        return;

    stack->arr[(stack->top) + 1] = e;
    stack->top += 1;
}

int length(struct Stack *stack)
{
    return stack->top + 1;
}

char pop(struct Stack *stack)
{
    if (is_empty(stack))
        return '\0';

    return stack->arr[stack->top--];
}

char top(struct Stack *stack)
{
    return stack->arr[stack->top];
}

int validate(char *expr)
{

    char c;
    int i = 0;
    int expr_len = strlen(expr);
    struct Stack *stack = create_stack(100);

    for (int i = 0; i < expr_len; i++)
    {
        c = expr[i];
        if (c == '(')
        {
            push(stack, c);
        }
        else if (c == ')')
        {
            if (is_empty(stack))
            {
                return 0;
            }
            else
            {

                pop(stack);
            }
        }
    }

    return is_empty(stack);
}

int main()
{
    char expr[MAX_EXPR_LENTGH];
    printf("Input expression : ");
    scanf("%s", expr);

    printf(" expr validation result : %d", validate(expr));

    return 0;
}