/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_top.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbruck <sbruck@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 20:17:43 by sbruck            #+#    #+#             */
/*   Updated: 2025/03/04 11:58:23 by sbruck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    prep_for_pushing(t_stack **stack, t_stack *top) //prep for push
{
    int len;
    int up_moves;
    int down_moves;

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

void    prep_b_to_push(t_mothership *m, t_stack *top) //prep for push
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

    stack = m->stack_a;
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
