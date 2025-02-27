/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   the_turk_push_to_top.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbruck <sbruck@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 20:17:43 by sbruck            #+#    #+#             */
/*   Updated: 2025/02/27 00:53:03 by sbruck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    push_to_top_a(t_mothership *m, t_stack *top)
{
    t_stack **stack;
    stack = m->stack_a;
    int len = count_nodes(stack);
    int up_moves = top->index;
    int down_moves = len - top->index;

    if (up_moves < down_moves)
    {
        while (*stack != top)
            ra(stack);
    }
    else
    {
        while (*stack != top)
            rra(stack);
    }
}


void    push_to_top_b(t_mothership *m, t_stack *top)
{
    while (top!= *(m->stack_b))
    {
        if (top->target->above_median)
        {
            rb(m->stack_b);
        }
        else
        {
            rrb(m->stack_b);
        }
    }
}