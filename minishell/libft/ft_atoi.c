/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knjaloun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 17:06:05 by knjaloun          #+#    #+#             */
/*   Updated: 2024/10/28 18:29:40 by knjaloun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(const char *nptr)
{
	int	index;

	index = 0;
	while (nptr[index] == ' ' || nptr[index] == '\t'
		|| nptr[index] == '\n' || nptr[index] == '\r'
		|| nptr[index] == '\v' || nptr[index] == '\f')
	{
		index++;
	}
	return (index);
}

int	ft_atoi(const char *nptr)
{
	int	sum;
	int	index;
	int	isneg;

	sum = 0;
	index = ft_isspace(nptr);
	isneg = 1;
	if (nptr[index] == '-' || nptr[index] == '+')
	{
		if (nptr[index] == '-')
			isneg = -1;
		index++;
		if (nptr[index] == '-' || nptr[index] == '+')
			return (0);
	}
	while (nptr[index] >= '0' && nptr[index] <= '9')
	{
		sum = sum * 10 + (nptr[index] - '0');
		index++;
	}
	return (sum * isneg);
}
