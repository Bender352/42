/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbruck <sbruck@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 13:48:39 by sbruck            #+#    #+#             */
/*   Updated: 2025/03/08 20:44:24 by sbruck           ###   ########.fr       */
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
    static t_mothership m;
    int flag1;

    m.stack_a = &stack_a;
    m.stack_b = &stack_b;
    flag1 = 1;
    check_input(arg, argv);
    if (2 == arg)
        m.temp = ft_split(argv[1], ' ');
    else
    {
        m.temp = argv + 1;
        flag1 = 0;
    }
    fill_stack(&m);
    check_for_doubles(&m, flag1);
    sort_method(&m);
    free_stack(&stack_a, &stack_b);
    if(flag1)
        free_array(m.temp);
    m.temp = NULL;
    return (0);
}

void    sort_method(t_mothership *m)
{
    int total_nodes;

    total_nodes = count_nodes(m->stack_a);
    if(total_nodes <= 2)
        sort2(m->stack_a);
    else if (total_nodes <= 3)
        sort3(m->stack_a);
    else
        do_the_turk(m);
}

void print_stack(t_stack **stack)
{
    t_stack *buf;

    buf = *stack;
    while (buf)
    {
        printf("%ld\n", buf->i);
        buf = buf->next;
    }
}

