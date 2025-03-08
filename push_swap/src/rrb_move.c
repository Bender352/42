/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrb_move.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbruck <sbruck@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 00:11:18 by sbruck            #+#    #+#             */
/*   Updated: 2025/03/08 21:04:54 by sbruck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rev_rotate_stack(t_stack **stack)
{
	t_stack	*first;
	t_stack	*last;

	if (!stack || !(*stack) || !(*stack)->next)
		return ;
	first = (*stack);
	last = last_node((*stack));
	last->prev->next = NULL;
	last->prev = NULL;
	last->next = first;
	first->prev = last;
	(*stack) = last;
}

void	rrb(t_stack **stack_b)
{
	rev_rotate_stack(stack_b);
	print_move("rrb");
}
