/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shove_things_arround.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbruck <sbruck@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 21:23:21 by sbruck            #+#    #+#             */
/*   Updated: 2025/03/08 21:51:00 by sbruck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	shove_b_to_a(t_mothership *m)
{
	prep_for_pushing_a(m->stack_a, (*m->stack_b)->target);
	pa(m);
}

void	shove_a_to_b(t_mothership *m)
{
	t_stack	*cheapest;

	cheapest = get_cheapest_node(m->stack_a);
	if (cheapest->above_median && cheapest->above_median)
		rr_all(m, cheapest);
	else if (!cheapest->above_median && !cheapest->above_median)
		rrr_all(m, cheapest);
	prep_for_pushing_a(m->stack_a, cheapest);
	prep_for_pushing_b(m->stack_b, cheapest->target);
	pb(m);
}
