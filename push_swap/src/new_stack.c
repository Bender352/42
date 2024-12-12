#include <push_swap.h>

t_stack *new_stack(int  i)
{
    t_stack *stack;

    stack = malloc(sizeof(stack));
    stack->i = i;
    stack->next = NULL;
    stack->prev = NULL;
    return (stack);
}