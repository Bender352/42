/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   the_turk.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbruck <sbruck@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 16:15:30 by sbruck            #+#    #+#             */
/*   Updated: 2025/02/07 22:30:28 by sbruck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int cal_cost_push(t_stack **stack)
{
    (void) stack;
    return (0);
}

int cal_cost_rotate (t_stack **stack)
{
    (void) stack;
    return (0);
}

long    find_median (t_stack **stack)
{
    long        buf;
    t_stack     *list;
    int         count;

    buf = 0;
    count = 0;
    list = *stack;
    while (list)
    {
        buf += list->i;
        list = list->next;
        count++;
    }
    return (buf / count);
}

t_stack *find_low_coast (t_stack **stack)
{
    
}