/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   the_turk.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbruck <sbruck@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 16:15:30 by sbruck            #+#    #+#             */
/*   Updated: 2025/02/15 20:46:06 by sbruck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
        shove_b_to_a(m);
    }
    sort3(m->stack_a);

}

void ini_stack (t_mothership *m)
{
    set_index(m->stack_a);
    set_index(m->stack_b);
    set_target(m);
    set_cost(m);
    cheapest_node(m->stack_a);
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

void    set_target(t_mothership *m)
{
    t_stack *a;
    t_stack *b;
    t_stack *target;
    long    match_index;

    match_index = LONG_MIN;
    a = *(m->stack_a);
    b = *(m->stack_b);
    while (a)
    {
        while (b)
        {
            if (b->i < a->i && b->i > match_index)
            {
                match_index = b->i;
                target = b;
            }
            b = b->next;
        }
        if (match_index == LONG_MIN)
            a->target = find_highest_i_node(b);
        else
            a->target = target;
        a = a->next;
    }
}

void    set_cost(t_mothership *m)
{
    (void)m;

    
}

void    cheapest_node(t_stack **stack)
{
    (void)stack;

    
}

void    shove_b_to_a(t_mothership *m)
{
    (void)m;

    
}
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

t_stack *find_highest_i_node(t_stack **stack)
{
    long    i;
    t_stack *a;
    t_stack *biggest;

    i = LONG_MIN;
    a = *(stack);
    while (a)
    {
        if (a->i > i)
        {   
            i = a->i;
            biggest = a;
        }
        a = a->next;
    }
    if (i == LONG_MIN)
        return (*(stack));
    else
        return (biggest);
}