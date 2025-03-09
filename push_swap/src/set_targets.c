/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_targets.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbruck <sbruck@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 01:23:33 by sbruck            #+#    #+#             */
/*   Updated: 2025/03/09 16:30:28 by sbruck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_target_a(t_mothership *m)
{
	t_stack	*a;
	t_stack	*b;
	t_stack	*target;
	long	match_index;

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

void	set_target_b(t_mothership *m)
{
	t_stack	*a;
	t_stack	*b;
	t_stack	*target;
	long	match_index;

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
