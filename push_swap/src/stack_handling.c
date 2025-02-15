/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbruck <sbruck@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 14:07:54 by sven              #+#    #+#             */
/*   Updated: 2025/02/07 18:03:58 by sbruck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    r(t_stack **stack)
{
    t_stack *first;
    t_stack *last;

    if(!stack || !(*stack) || !(*stack)->next)
        return;
    first = (*stack);
    last = last_node((*stack));
    last->next = first;
    first->prev = last;
    (*stack) = first->next;
    first->next = NULL;
    (*stack)->prev = NULL;
}

void    rr(t_stack **stack)
{
    t_stack *first;
    t_stack *last;

    if(!stack || !(*stack) || !(*stack)->next)
        return;
    first = (*stack);
    last = last_node((*stack));
    last->prev->next = NULL;
    last->prev = NULL;
    last->next = first;
    first->prev = last;
    (*stack) = last;
}

t_stack *last_node(t_stack  *list)
{
    t_stack *buf;
    
    if(!list)
        return (NULL);
    buf = list;
    while (buf->next)
        buf = buf->next;
    return (buf);    
}

void    p(t_stack **stack_from, t_stack **stack_to)
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

void s(t_stack **stack)
{
    t_stack *first;
    t_stack *second;

    if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
        return;
    first = *stack;
    second = first->next;
    first->next = second->next;
    if (second->next)
        second->next->prev = first;
    second->next = first;
    second->prev = NULL;
    first->prev = second;
    (*stack) = second;
}
