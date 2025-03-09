/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_stacks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbruck <sbruck@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 20:16:03 by sbruck            #+#    #+#             */
/*   Updated: 2025/03/09 16:25:02 by sbruck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rr_all(t_mothership *m, t_stack *cheapy)
{
	while (*(m->stack_a) != cheapy && *(m->stack_b) != cheapy->target)
	{
		rr(m->stack_a, m->stack_b);
		set_index(m->stack_a);
		set_index(m->stack_b);
	}
}

void	rrr_all(t_mothership *m, t_stack *cheapy)
{
	while (*(m->stack_a) != cheapy && *(m->stack_b) != cheapy->target)
	{
		rrr(m->stack_a, m->stack_b);
		set_index(m->stack_a);
		set_index(m->stack_b);
	}
}
