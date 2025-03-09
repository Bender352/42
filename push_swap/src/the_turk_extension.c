/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   the_turk_extension.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbruck <sbruck@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 16:37:51 by sbruck            #+#    #+#             */
/*   Updated: 2025/03/09 16:43:34 by sbruck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_cheapest_node(t_stack **stack)
{
	long	lowest_value;
	t_stack	*a;
	t_stack	*lowest_node;

	if (!stack && !(*(stack)))
		return ;
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
