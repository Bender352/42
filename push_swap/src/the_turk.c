/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   the_turk.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbruck <sbruck@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 16:15:30 by sbruck            #+#    #+#             */
/*   Updated: 2025/03/08 22:04:47 by sbruck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_the_turk(t_mothership *m)
{
	sort_stack(m);
}

void	sort_stack(t_mothership *m)
{
	int	len;

	len = count_nodes(m->stack_a);
	if (len-- > 3 && !is_stack_sorted(m->stack_a))
		pb(m);
	if (len-- > 3 && !is_stack_sorted(m->stack_a))
		pb(m);
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

static void	set_cost_2(int move_a, int move_b, t_mothership *m)
{
	t_stack	*a;

	a = *(m->stack_a);
	if ((a->above_median && a->target->above_median) || (!a->above_median
			&& !a->target->above_median))
	{
		if (move_a > move_b)
			a->cost_push = move_a;
		else
			a->cost_push = move_b;
	}
	else
		a->cost_push = move_a + move_b;
}

void	set_cost(t_mothership *m)
{
	t_stack	*a;
	int		move_a;
	int		move_b;

	a = *(m->stack_a);
	while (a)
	{
		if (a->index < count_nodes(m->stack_a) - a->index)
			move_a = a->index;
		else
			move_a = count_nodes(m->stack_a) - a->index;
		if (a->target->index < count_nodes(m->stack_b) - a->target->index)
			move_b = a->target->index;
		else
			move_b = count_nodes(m->stack_b) - a->target->index;
		set_cost_2(move_a, move_b, m);
		a = a->next;
	}
}

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
