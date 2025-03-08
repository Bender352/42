/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   the_turk.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbruck <sbruck@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 16:15:30 by sbruck            #+#    #+#             */
/*   Updated: 2025/03/08 15:14:00 by sbruck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    do_the_turk(t_mothership *m)
{
    sort_stack(m);
}

void    sort_stack(t_mothership *m) //sort stacks
{
    int len;

    len = count_nodes(m->stack_a);
    if (len-- > 3 && !is_stack_sorted(m->stack_a))
        pb(m);
    if (len-- > 3 && !is_stack_sorted(m->stack_a))
        pb(m);
    while (len-- > 3 && !is_stack_sorted(m->stack_a))
    {
        ini_stack_a(m);
        shove_a_to_b(m); //move_a_to_b
    }
    sort3(m->stack_a);
    while (*(m->stack_b))
    {
        ini_stack_b(m);
        shove_b_to_a(m); //move_b_to_a
    }
    set_index(m->stack_a); //current index
    min_on_top(m);
}

void set_cost(t_mothership *m) //cost_analyse
{
    int len_a = count_nodes(m->stack_a);
    int len_b = count_nodes(m->stack_b);
    t_stack *a = *(m->stack_a);
    int cost_up_a;
    int cost_down_a;
    int cost_up_b;
    int cost_down_b;
    int move_a;
    int move_b;

    while (a)
    {
        cost_up_a = a->index;
        cost_down_a = len_a - a->index;
        cost_up_b = a->target->index;
        cost_down_b = len_b - a->target->index;
        if(cost_up_a < cost_down_a)
            move_a = cost_up_a;
        else
            move_a = cost_down_a;
        if(cost_up_b < cost_down_b)
            move_b = cost_up_b;
        else
            move_b = cost_down_b;
        //move_a = (cost_up_a < cost_down_a) ? cost_up_a : cost_down_a;
        //move_b = (cost_up_b < cost_down_b) ? cost_up_b : cost_down_b;
        if ((a->above_median && a->target->above_median) ||
            (!a->above_median && !a->target->above_median))
            //a->cost_push = (move_a > move_b) ? move_a : move_b;
            if(move_a > move_b)
                a->cost_push = move_a;
            else
                a->cost_push = move_b;
        else
            a->cost_push = move_a + move_b; // Normal case: sum of separate moves
        a = a->next;
    }
}

void    set_cheapest_node(t_stack **stack) //set_cheapest
{
    long    lowest_value;
    t_stack *a;
    t_stack *lowest_node;

    if(!stack && !(*(stack)))
        return;
    a = *(stack);
    lowest_value = LONG_MAX;
    while (a)
    {
        if (a->cost_push < lowest_value)
        {
            lowest_value = a->cost_push;
            lowest_node = a;  
        }
        a = a->next;
    }
    lowest_node->cheapst = true;    
}

void    shove_b_to_a(t_mothership *m)
{
    prep_for_pushing_a(m->stack_a, (*m->stack_b)->target);
    pa(m);
}

void shove_a_to_b(t_mothership *m)
{
    t_stack *cheapest;
    
    cheapest = get_cheapest_node(m->stack_a);
    if(cheapest->above_median && cheapest->above_median)
        rr_all(m, cheapest);
    else if(!cheapest->above_median && !cheapest->above_median)
        rrr_all(m, cheapest);
    prep_for_pushing_a(m->stack_a, cheapest);
    prep_for_pushing_b(m->stack_b, cheapest->target);
    pb(m);
/*
    while (count_nodes(m->stack_a) > 3) 
    {
        set_cost(m);
        set_cheapest_node(m->stack_a); 
        

        if (!cheapest)
            return;

        prep_a_to_push(m, cheapest);
        pa(m);
    }
*/
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

t_stack *get_cheapest_node(t_stack **a)
{
    t_stack *node;

    if(!a || !(*a))
        return NULL;
    node = *(a);
    while (node)
    {
        if(node->cheapst == true)
            return node;
        node = node->next;
    }
        return NULL;
}

void    min_on_top(t_mothership *m)
{
    t_stack **a;
    t_stack *smallest_node;

    a = m->stack_a;
    smallest_node = find_smallest_i_node(m->stack_a);
    while((*a)->i != smallest_node->i)
    {
        if(smallest_node->above_median)
            ra(a);
        else
            rra(a);
    }
}

t_stack *find_smallest_i_node(t_stack **stack)
{
    long    i;
    t_stack *a;
    t_stack *smallest;

    i = LONG_MAX;
    a = *(stack);
    while (a)
    {
        if (a->i < i)
        {   
            i = a->i;
            smallest = a;
        }
        a = a->next;
    }
    if (i == LONG_MAX)
        return (*(stack));
    else
        return (smallest);
}