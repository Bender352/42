/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   the_turk_push_to_top.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbruck <sbruck@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 20:17:43 by sbruck            #+#    #+#             */
/*   Updated: 2025/03/03 18:41:29 by sbruck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    push_to_top_a(t_mothership *m, t_stack *top)
{
    t_stack **stack;
    int len;
    int up_moves;
    int down_moves;

    stack = m->stack_a;
    len = count_nodes(stack);
    up_moves = top->index;
    down_moves = len - top->index;
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
    /*
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
    */
    t_stack **stack;
    int len;
    int up_moves;
    int down_moves;

    stack = m->stack_b;
    len = count_nodes(stack);
    up_moves = top->index;
    down_moves = len - top->index;
    if (up_moves < down_moves)
    {
        while (*stack != top)
            rb(stack);
    }
    else
    {
        while (*stack != top)
            rrb(stack);
    }


}