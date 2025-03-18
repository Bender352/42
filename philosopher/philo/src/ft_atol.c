/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbruck <sbruck@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 07:56:11 by sbruck            #+#    #+#             */
/*   Updated: 2025/03/18 08:13:35 by sbruck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

long	ft_atol(char *str)
{
	long	number;
	int		i;
	int		sign;

	number = 0;
	i = 0;
	sign = 1;
	while((str[i] >= 7 && str[i] <= 13) || str[i] == 32)	//skips all spaces
		i++;
	i = 0;
	while(str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		else
			sign = 1;
		i++;
	}
	while(str[i] >= 0 && str[i] <= 9)
	{
		number = number * 10 + str[i] - '0';
		i++;
	}
	if (number < 0 || number > INT_MAX)
		return (-1);

	return (number * sign);
}