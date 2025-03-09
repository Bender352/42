/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_for_doubles.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbruck <sbruck@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 20:04:48 by sbruck            #+#    #+#             */
/*   Updated: 2025/03/08 21:27:48 by sbruck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_for_doubles(t_mothership *m, int flag1)
{
	long long int	i;
	t_stack			*stack1;
	t_stack			*stack2;

	stack1 = *(m->stack_a);
	stack2 = *(m->stack_a);
	while (stack1)
	{
		i = stack1->i;
		stack2 = stack1->next;
		while (stack2)
		{
			if (stack2->i == i)
			{
				free_stack(m->stack_a, 0);
				if (flag1)
					free_array(m->temp);
				m->temp = NULL;
				do_error();
			}
			stack2 = stack2->next;
		}
		stack1 = stack1->next;
	}
}
