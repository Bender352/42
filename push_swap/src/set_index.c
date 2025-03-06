/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_index.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbruck <sbruck@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 13:14:43 by sbruck            #+#    #+#             */
/*   Updated: 2025/03/06 21:36:38 by sbruck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void set_index (t_stack **stack) //current_index
{
    int i;
    int median;
    t_stack *list;

    if (!stack && !(*stack))
        return;
    median = count_nodes(stack) / 2;
    list = (*stack);
    i = 0;
    while (list)
    {
        list->index = i;
        if (i <= median)
            list->above_median = true;
        else
            list->above_median = false;
        list = list->next;
        i++;
    }
}