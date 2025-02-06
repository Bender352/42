/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbruck <sbruck@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 08:29:44 by sbruck            #+#    #+#             */
/*   Updated: 2025/02/06 09:36:33 by sbruck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    highest_on_top(t_stack  **stack)
{
    if (element_count(*stack) < 2)
        return;
    if ((*stack)->i < (*stack)->next->i)
        s(stack);
    return;
}

void    push_all_to_a(t_stack **stack_a, t_stack **stack_b)
{
    while ((*stack_b))
    {
        p(stack_b, stack_a);
        (*stack_b) = (*stack_b)->next;
    }
}

void    bubble_sort(t_stack **stack_a, t_stack **stack_b)
{
    int     nbr;

    nbr = 0;
    //check if stack_a has only 3 nodes if yes push them to sort3 if not push them to stack_b
    if (element_count(*stack_a) <= 2)
    {
        if ((*stack.a)->i < (*stack.a)->next->i)
            s(stack);
        push_all_to_a (stack_a, stack_b);
        return;
    }
    else
    {
        p(stack_a, stack_b);
        highest_on_top(stack_b);
    }
    //stack_b highest on top sorting

}

