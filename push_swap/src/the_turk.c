/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   the_turk.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbruck <sbruck@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 16:15:30 by sbruck            #+#    #+#             */
/*   Updated: 2025/02/09 01:29:03 by sbruck           ###   ########.fr       */
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

t_stack *find_low_coast (t_stack **stack)
{
    (void)stack;
    return NULL;
}

void ini_stack (t_mothership *m)
{
    set_index(m->stack_a);
    set_index(m->stack_b);
    set_target(m);
    set_cost(m);
    cheapest_node(stack_a);
}

void set_index (t_stack **stack)
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

void sort_stack (t_mothership *m)
{
    int len;
    int i;

    len = count_nodes(m->stack_a);
    i = 0;
    while (i < 2)
    {   
        if (len-- > 3 && is_stack_sorted(m->stack_a))
        {
            p (m->stack_a, m->stack_b);
            print_move("pa");
        }
        i++;
    }
    while (len-- > 3 && is_stack_sorted(m->stack_a))
    {
        ini_stack(m);
        shove_b_to_a;
    }
    sort3(m->stack_a);



}