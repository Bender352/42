/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_nodes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbruck <sbruck@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 16:44:31 by sbruck            #+#    #+#             */
/*   Updated: 2025/02/06 09:36:33 by sbruck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int find_smallest (t_stack **list)
{
    int i;
    int index;
    int track;
    t_stack     *stack;

    i = 0;
    index = 0;
    track = 0;
    if (!list && !*list)
        return (-1);
    stack = *list;
    i = stack->i;
    while (*stack)
    {
        if (i < stack->i)
        {
            i = stack->i;
            index = track;
        }
        track++;
        stack = stack->next;
    }
    return (index);
}

