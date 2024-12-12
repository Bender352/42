/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbruck <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 14:51:29 by sbruck            #+#    #+#             */
/*   Updated: 2024/07/28 14:51:30 by sbruck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	*i;
	int	a;
	int	diff;

	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	diff = max - min;
	i = (malloc(diff * sizeof(*i)));
	if (i == NULL)
	{
		*range = NULL;
		return (-1);
	}
	a = 0;
	while (min < max)
	{
		i[a] = min;
		a++;
		min++;
	}
	*range = i;
	return (a);
}
