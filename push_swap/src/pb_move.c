/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pb_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbruck <sbruck@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 00:10:59 by sbruck            #+#    #+#             */
/*   Updated: 2025/02/27 00:59:38 by sbruck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void    do_pb(t_stack **stack_from, t_stack **stack_to)
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

void    pb(t_mothership *m)
{
    print_move("pb");
    do_pb (m->stack_a, m->stack_b);
}
