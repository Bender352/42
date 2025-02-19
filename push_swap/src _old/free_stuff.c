#include "push_swap.h"

void    free_stack(t_stack  **stack_a, t_stack **stack_b)
{
	t_stack *temp;
    if (stack_a && *stack_a)
    {
        while (*stack_a != NULL)
        {
            temp = (*stack_a)->next;
            free(*stack_a);
            *stack_a = temp;
        }
    }
	if(stack_b && *stack_b)
	{
		while (*stack_b != NULL)
		{
			temp = *stack_b;
			*stack_b = (*stack_b)->next;
			free(temp);
		}	
	}
}

void free_array(char **pntstr)
{
    int i;

    i = 0;
    if (pntstr)
    {
        while (pntstr[i])
        {
            free(pntstr[i]);
            pntstr[i] = NULL;
            i++;
        }
    }
    free(pntstr);
    pntstr = NULL;
}
