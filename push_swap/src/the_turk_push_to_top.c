/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   the_turk_push_to_top.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbruck <sbruck@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 20:17:43 by sbruck            #+#    #+#             */
/*   Updated: 2025/02/27 18:36:39 by sbruck           ###   ########.fr       */
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

/*
void perform_rotations(t_stack **a, t_stack **b, int cost_a, int cost_b)
{
    // Rotate both stacks upward
    while (cost_a > 0 && cost_b > 0)
    {
        rotate(a);
        rotate(b);
        cost_a--;
        cost_b--;
        ft_printf("rr\n");
    }
    // Reverse rotate both stacks
    while (cost_a < 0 && cost_b < 0)
    {
        reverse_rotate(a);
        reverse_rotate(b);
        cost_a++;
        cost_b++;
        ft_printf("rrr\n");
    }
    // Complete remaining rotations for stack A
    while (cost_a > 0)
    {
        rotate(a);
        cost_a--;
        ft_printf("ra\n");
    }
    while (cost_a < 0)
    {
        reverse_rotate(a);
        cost_a++;
        ft_printf("rra\n");
    }
    // Complete remaining rotations for stack B
    while (cost_b > 0)
    {
        rotate(b);
        cost_b--;
        ft_printf("rb\n");
    }
    while (cost_b < 0)
    {
        reverse_rotate(b);
        cost_b++;
        ft_printf("rrb\n");
    }
}
*/


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