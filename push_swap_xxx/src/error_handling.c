/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbruck <sbruck@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 14:28:27 by sbruck            #+#    #+#             */
/*   Updated: 2025/03/08 21:34:42 by sbruck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_format(char **str)
{
	(void)str;
}

int	isnumber(int i)
{
	(void)i;
	if (i >= 0)
	{
	}
	return (0);
}

void	show_error(t_mothership *m)
{
	free_stack(m->stack_a, m->stack_b);
	free_array(m->temp);
	perror(m->error_msg);
	exit(1);
}
