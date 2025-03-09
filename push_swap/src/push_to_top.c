/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_top.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbruck <sbruck@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 20:17:43 by sbruck            #+#    #+#             */
/*   Updated: 2025/03/09 16:22:04 by sbruck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	prep_for_pushing_a(t_stack **stack, t_stack *top) //prep for push
{
	int	len;
	int	up_moves;
	int	down_moves;

	len = count_nodes(stack);
	up_moves = top->index;
	down_moves = len - top->index;
	if (up_moves < down_moves)
	{
		while (*stack != top)
			ra(stack);
	}
	else
	{
		while (*stack != top)
			rra(stack);
	}
}

void	prep_for_pushing_b(t_stack **stack, t_stack *top) //prep for push
{
	int	len;
	int	up_moves;
	int	down_moves;

	len = count_nodes(stack);
	up_moves = top->index;
	down_moves = len - top->index;
	if (up_moves < down_moves)
	{
		while (*stack != top)
			rb(stack);
	}
	else
	{
		while (*stack != top)
			rrb(stack);
	}
}

void	prep_b_to_push(t_mothership *m, t_stack *top) //prep for push
{
	t_stack	**stack;
	int		len;
	int		up_moves;
	int		down_moves;

	stack = m->stack_a;
	len = count_nodes(stack);
	up_moves = top->index;
	down_moves = len - top->index;
	if (up_moves < down_moves)
	{
		while (*stack != top)
			rb(stack);
	}
	else
	{
		while (*stack != top)
			rrb(stack);
	}
}
