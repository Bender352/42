/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   the_turk.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbruck <sbruck@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 16:15:30 by sbruck            #+#    #+#             */
/*   Updated: 2025/02/22 19:46:42 by sbruck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


/***************************************** */
//34:45 start from here to review the code!
/***************************************** */

int cycle = 0;

void    do_the_turk(t_mothership *m)
{
    sort_stack(m);
}

void    sort_stack(t_mothership *m)
{
    int len;

    len = count_nodes(m->stack_a);
    if (len-- > 3 && !is_stack_sorted(m->stack_a))
    {
        p(m->stack_a, m->stack_b);
        print_move("pb");
    }
    if (len-- > 3 && !is_stack_sorted(m->stack_a))
    {
        p(m->stack_a, m->stack_b);
        print_move("pb");
    }
    while (len-- > 3 && !is_stack_sorted(m->stack_a))
    {
        ini_stack_a(m);
        shove_a_to_b(m);
    }
    sort3(m->stack_a);
    while (*(m->stack_b))
    {
        ini_stack_b(m);
        shove_b_to_a(m);
    }
    set_index(m->stack_a);
    min_on_top(m);
}

void    ini_stack_a(t_mothership *m)
{
    set_index(m->stack_a);
    set_index(m->stack_b);
    set_target_a(m);
    set_cost(m);
    set_cheapest_node(m->stack_a);
}

void    ini_stack_b(t_mothership *m)
{
    set_index(m->stack_a);
    set_index(m->stack_b);
    set_target_b(m);
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
            list->above_median = false;
        else
            list->above_median = true;
        list = list->next;
        i++;
    }
}

void    set_target_a(t_mothership *m)
{
    t_stack *a;
    t_stack *b;
    t_stack *target;
    long    match_index;
   
    a = *(m->stack_a);
    while (a)
    {
        match_index = LONG_MIN;
        b = *(m->stack_b);
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
            a->target = find_highest_i_node(m->stack_b);
        else
            a->target = target;
        a = a->next;
    }
}
void    set_target_b(t_mothership *m)
{
    t_stack *a;
    t_stack *b;
    t_stack *target;
    long    match_index;

    b = *(m->stack_b);
    while (b)
    {
        match_index = LONG_MAX;
        a = *(m->stack_a);
        while (a)
        {
            if (a->i > b->i && a->i < match_index)
            {
                match_index = a->i;
                target = a;
            }
            a = a->next;
        }
        if (match_index == LONG_MAX)
            b->target = find_smallest_i_node(m->stack_a);
        else
            b->target = target;
        b = b->next;
    }
}
/* //MY VERSION
void    set_cost(t_mothership *m)
{
    int len_a;
    int len_b;
    t_stack *a;

    len_a = count_nodes(m->stack_a);
    len_b = count_nodes(m->stack_b);
    a = *(m->stack_a);
    while (a)
    {
        a->cost_push = a->index;
        if (!(a->above_median))
            a->cost_push = len_a - a->index;
        if (a->target->above_median)
            a->cost_push += a->target->index;
        else
            a->cost_push += len_b - a->target->index;
        a = a->next;
    }    
}
*/

void set_cost(t_mothership *m)
{
    int len_a = count_nodes(m->stack_a);
    int len_b = count_nodes(m->stack_b);
    t_stack *a = *(m->stack_a);

    while (a)
    {
        int cost_up_a = a->index;
        int cost_down_a = len_a - a->index;
        int cost_up_b = a->target->index;
        int cost_down_b = len_b - a->target->index;

        // Find the best way to move a and b separately
        int move_a = (cost_up_a < cost_down_a) ? cost_up_a : cost_down_a;
        int move_b = (cost_up_b < cost_down_b) ? cost_up_b : cost_down_b;

        // If they are in the same half, take the max (using rr or rrr)
        if ((a->above_median && a->target->above_median) ||
            (!a->above_median && !a->target->above_median))
        {
            a->cost_push = (move_a > move_b) ? move_a : move_b;
        }
        else
        {
            a->cost_push = move_a + move_b; // Normal case: sum of separate moves
        }

        a = a->next;
    }
}





void    set_cheapest_node(t_stack **stack)
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
    push_to_top_a(m, (*m->stack_b)->target);
    p(m->stack_b, m->stack_a);
    print_move("pb");
}
/* //MY VERSION
void    shove_a_to_b(t_mothership *m)
{
    t_stack *cheapy;
    int i = 0;

    ini_stack_a(m);
    ini_stack_b(m);
    cheapy = get_cheapest_node(m->stack_a);
    i = count_nodes(m->stack_a);
    if (i)
    {
        
    }
    if(cheapy->above_median && cheapy->target->above_median)
        rr_all(m, cheapy);
    else if(!(cheapy->above_median) && !(cheapy->target->above_median))
        rrr_all(m, cheapy);
    i = count_nodes(m->stack_a);
    cycle++;
    push_to_top_a(m, cheapy);
    push_to_top_b(m, cheapy->target);
    p(m->stack_a, m->stack_b);
    print_move("pb");
}
*/

void shove_a_to_b(t_mothership *m)
{
    while (count_nodes(m->stack_a) > 3) // Leave 3 nodes in A for final sorting
    {
        set_cost(m);
        set_cheapest_node(m->stack_a);  // No need for double pointer
        t_stack *cheapest = get_cheapest_node(m->stack_a);

        if (!cheapest)
            return;

        push_to_top_a(m, cheapest);  // Move to the top optimally
        p(m->stack_a, m->stack_b);    // Push to B
    }
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

    node = *(a);
    while (node)
    {
        if (node->cheapst)
            return (node);
        node = node->next;
    }
    return NULL;
}
void    rr_all(t_mothership *m, t_stack *cheapy)
{
    while (*(m->stack_a) != cheapy && *(m->stack_b) != cheapy->target)
    {
        rotate_stack(m->stack_a);
        rotate_stack(m->stack_b);
        print_move("rr");
        set_index(m->stack_a);
        set_index(m->stack_b);
    }
}
void    rrr_all(t_mothership *m, t_stack *cheapy)
{
    while (*(m->stack_a) != cheapy && *(m->stack_b) != cheapy->target)
    {
        rev_rotate_stack(m->stack_a);
        rev_rotate_stack(m->stack_b);
        print_move("rrr");
        set_index(m->stack_a);
        set_index(m->stack_b);

    }
}
/*//MYVERSION
void    push_to_top_a(t_mothership *m, t_stack *top)
{
    if (!top)
        return;


    while (top != *(m->stack_a))
    {
        if (top->above_median)
        {
            rotate_stack(m->stack_a);
            print_move("ra");
        }
        else
        {
            rev_rotate_stack(m->stack_a);
            print_move("rra");
        }
    }
*/
void    push_to_top_a(t_mothership *m, t_stack *top)
{
    t_stack **stack;
    stack = m->stack_a;
    int len = count_nodes(stack);
    int up_moves = top->index;
    int down_moves = len - top->index;

    if (up_moves < down_moves)
    {
        while (*stack != top)
            rotate_stack(stack);  // ra
    }
    else
    {
        while (*stack != top)
            rev_rotate_stack(stack);  // rra
    }
}


void    push_to_top_b(t_mothership *m, t_stack *top)
{
    while (top!= *(m->stack_b))
    {
        if (top->target->above_median)
        {
            rotate_stack(m->stack_b);
            print_move("rb");
        }
        else
        {
            rev_rotate_stack(m->stack_b);
            print_move("rrb");
        }
    }
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
        {
            rotate_stack(a);
            print_move("ra");
        }
        else
        {
            rev_rotate_stack(a);
            print_move("rra");
        }
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