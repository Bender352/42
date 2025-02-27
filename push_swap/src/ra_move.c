/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbruck <sbruck@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 00:11:02 by sbruck            #+#    #+#             */
/*   Updated: 2025/02/27 00:59:25 by sbruck           ###   ########.fr       */
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

void    ra(t_stack **stack_a)
{
    rotate_stack(stack_a);
    print_move("ra");
}
