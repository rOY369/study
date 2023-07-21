#include <stdio.h>
#include <stdlib.h>

struct Stack
{
    int top;
    unsigned int capacity;
    int *arr;
};

struct Stack *create_stack(unsigned int capacity)
{

    struct Stack *stack = (struct Stack *)malloc(sizeof(struct Stack));

    stack->capacity = capacity;
    stack->top = -1;
    stack->arr = (int *)malloc(sizeof(int) * capacity);

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

int pop(struct Stack *stack)
{
    if (is_empty(stack))
        return 0;

    return stack->arr[stack->top--];
}

int top(struct Stack *stack)
{
    return stack->arr[stack->top];
}

int main()
{
    struct Stack *stack = create_stack(100);

    push(stack, 10);
    push(stack, 20);
    push(stack, 30);
    pop(stack);
    pop(stack);

    printf("%d popped from stack\n", pop(stack));

    printf("stack top : %d", top(stack));

    return 0;
}