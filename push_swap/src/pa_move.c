/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbruck <sbruck@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 00:10:56 by sbruck            #+#    #+#             */
/*   Updated: 2025/02/27 01:04:27 by sbruck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void    do_pa(t_stack **stack_from, t_stack **stack_to)
{
    t_stack *a;
    t_stack *b;

    if (!stack_from && (*stack_from) && !stack_to)
        return;
    a = (*stack_from);
    b = (*stack_to);
    if(a->next)
    {
        a->next->prev = NULL;
        *stack_from = (*stack_from)->next;
    }
    else
        (*stack_from) = NULL;
    if (!b)
    {
        *stack_to = a;
        a->next = NULL;
    }
    else
    {
        b->prev = a;
        a->next = b;
        *stack_to = a;
    }
}

void    pa(t_mothership *m)
{
    print_move("pa");
    do_pa (m->stack_b, m->stack_a);
}
