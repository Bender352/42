/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_interative_power.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbruck <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 16:09:16 by sbruck            #+#    #+#             */
/*   Updated: 2024/07/24 16:09:18 by sbruck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	i;

	i = 1;
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	while (power > 0)
	{
		i *= nb;
		power--;
	}
	return (i);
}
/*
#include <stdio.h>

int	main(void)
{
	int	nb;
	int	power;
	
	nb = 5;
	power = 5;
	printf("%d to the power of %d", nb, power);
	printf(" equals %d\n", ft_iterative_power(nb, power));

}
*/
