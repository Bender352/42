/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbruck <sbruck@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 13:48:39 by sbruck            #+#    #+#             */
/*   Updated: 2024/12/24 19:51:56 by sbruck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
-TO DO-
In case of error, it must display "Error" followed by a ’\n’ on the standard error.
Errors include for example: some arguments aren’t integers, some arguments are
bigger than an integer and/or there are duplicates.
*/

int main(int arg, char **argv)
{
    static t_stack  *stack_a;
    static t_stack  *stack_b;
    int total_nodes;
    int *flag_err;

    char    **temp;
    *flag_err = 0;
    arg = 2;
    if (arg != 2 && argv[1][0])
        return (0);
    else
        temp = ft_split(argv[1], ' ');
    total_nodes = fill_stack(&stack_a, temp);
    printf("Total nodes :    %d", total_nodes);
    r(&stack_a);
    free_stack(&stack_a, &stack_b);
    free_array(temp);
    temp = NULL;
    return (0);
}

void    sort_method(t_stack **stack_a, t_stack **stack_b, int total_nodes)
{
    if(total_nodes < 2)
        return;
    else if (total_nodes <= 3)
        sort3(stack_a);
    else if (total_nodes <= 5)
        return;
    else if (total_nodes <= 15)
        return;
    else if (total_nodes <= 100)
        return;
    else if (total_nodes <= 500)
        return;
}
void    print_move(char *str)
{
    if (str = pa)
}
