/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbruck <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 17:58:16 by sbruck            #+#    #+#             */
/*   Updated: 2024/07/24 17:58:17 by sbruck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int	i;

	i = 0;
	if (nb <= 0)
		return (0);
	else if (nb == 1)
		return (1);
	else
		while (i * i < nb && i < nb / 2)
			i++;
	if (nb == i * i)
		return (i);
	return (0);
}
/*
#include <stdio.h>

int 	main(void)
{
	int	i = 1600000000;
	printf("The square root of %d is ", i);
	printf("%d\n", ft_sqrt(i));
	return (0);
}
*/
