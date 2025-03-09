/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   need_space_file_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbruck <sbruck@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 21:22:02 by sbruck            #+#    #+#             */
/*   Updated: 2025/03/08 21:41:29 by sbruck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*find_highest_i_node(t_stack **stack)
{
	long	i;
	t_stack	*a;
	t_stack	*biggest;

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

t_stack	*get_cheapest_node(t_stack **a)
{
	t_stack	*node;

	if (!a || !(*a))
		return (NULL);
	node = *(a);
	while (node)
	{
		if (node->cheapst == true)
			return (node);
		node = node->next;
	}
	return (NULL);
}

void	min_on_top(t_mothership *m)
{
	t_stack	**a;
	t_stack	*smallest_node;

	a = m->stack_a;
	smallest_node = find_smallest_i_node(m->stack_a);
	while ((*a)->i != smallest_node->i)
	{
		if (smallest_node->above_median)
			ra(a);
		else
			rra(a);
	}
}

t_stack	*find_smallest_i_node(t_stack **stack)
{
	long	i;
	t_stack	*a;
	t_stack	*smallest;

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
