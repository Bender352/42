/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbruck <sbruck@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 00:11:10 by sbruck            #+#    #+#             */
/*   Updated: 2025/02/27 01:01:12 by sbruck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void    rotate_stack(t_stack **stack)
{
    t_stack *first;
    t_stack *last;

    if(!stack || !(*stack) || !(*stack)->next)
        return;
    first = (*stack);
    last = last_node((*stack));
    last->next = first;
    first->prev = last;
    (*stack) = first->next;
    first->next = NULL;
    (*stack)->prev = NULL;
}

void    rr(t_stack **stack_a, t_stack **stack_b)
{
    rotate_stack(stack_a);
    rotate_stack(stack_b);
    print_move("rr");
}
