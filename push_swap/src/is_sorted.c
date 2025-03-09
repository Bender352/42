/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbruck <sbruck@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 00:48:01 by sbruck            #+#    #+#             */
/*   Updated: 2025/03/09 16:13:33 by sbruck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	is_stack_sorted(t_stack **stack)
{
	t_stack	*list;

	if (!stack && !(*stack))
		return (1);
	list = (*stack);
	while (list)
	{
		if (list->next && list->i < list->next->i)
			list = list->next;
		else if (!list->next)
			break ;
		else
			return (false);
	}
	return (true);
}
