/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbruck <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 16:31:54 by sbruck            #+#    #+#             */
/*   Updated: 2024/07/24 16:31:58 by sbruck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_power(int nb, int power)
{
	if (!power)
		return (1);
	else if (power < 0)
		return (0);
	else
	{
		return (nb * ft_recursive_power(nb, power - 1));
	}
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
