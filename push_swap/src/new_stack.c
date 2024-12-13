/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbruck <sbruck@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 21:33:38 by sbruck            #+#    #+#             */
/*   Updated: 2024/12/13 19:56:49 by sbruck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack *new_stack(int  i)
{
    t_stack *stack;

    stack = malloc(sizeof(stack));
    stack->i = i;
    stack->next = NULL;
    stack->prev = NULL;
    return (stack);
}