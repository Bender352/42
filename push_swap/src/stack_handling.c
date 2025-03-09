/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbruck <sbruck@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 14:07:54 by sven              #+#    #+#             */
/*   Updated: 2025/03/09 16:31:42 by sbruck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*last_node(t_stack *list)
{
	t_stack	*buf;

	if (!list)
		return (NULL);
	buf = list;
	while (buf->next)
		buf = buf->next;
	return (buf);
}
