/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbruck <sbruck@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 08:29:44 by sbruck            #+#    #+#             */
/*   Updated: 2025/02/27 01:05:15 by sbruck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*
void    highest_on_top(t_stack  **stack)
{
    t_stack     *list;

    list = *stack;
    if (count_nodes(&list) <= 1)
        return;
    if (list->i < list->next->i)
    {
        s(&list);
        printf("%s\n", "SWAPED");
    }
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
    //check if stack_a has only 3 nodes if yes push them to sort3 if not push them to stack_b
    if (count_nodes(stack_a) <= 2)
    {
        if ((*stack_a)->i < (*stack_a)->next->i)
            s(stack_a);
        push_all_to_a (stack_a, stack_b);
        return;
    }
    else
    {
        while (count_nodes(stack_a) >= 2)
        {
            p(stack_a, stack_b);
            highest_on_top(stack_b);
            printf("\n%s\n", "Print stack a :");
            print_stack(stack_a);
            printf("%s\n", "Print stack b :");
            print_stack(stack_b);
        }
    }
    //stack_b highest on top sorting

}

*/