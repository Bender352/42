/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbruck <sbruck@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 13:53:30 by sbruck            #+#    #+#             */
/*   Updated: 2025/03/08 21:05:54 by sbruck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort3(t_stack **head)
{
	int	i;

	i = find_highest(head);
	if (0 == i)
	{
		ra(head);
	}
	else if (1 == i)
	{
		sa(head);
		ra(head);
	}
	i = find_smallest(head);
	if (1 == i)
	{
		sa(head);
	}
}
