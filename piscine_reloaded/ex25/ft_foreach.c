/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_foreach.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbruck <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 17:11:13 by sbruck            #+#    #+#             */
/*   Updated: 2024/10/19 17:11:15 by sbruck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_foreach(int *tab, int length, void (*f)(int))
{
	int	i;

	i = 0;
	while (i < length)
	{
		f(tab[i]);
		i++;
	}
}
/*
void	ft_putnbr(int nbr)
{
	int	i;
	char buffer[11];
	
	i = 0;
	if (nbr < 0)
	{
		write(1, "-", 1);
		nbr = nbr * -1;
	}
	if (nbr == 0)
	{
		write (1, "0", 1);
		return;	
	}
	while (nbr)
	{
		buffer[i] = (nbr % 10) + '0';
		nbr /= 10;
		i++;
	}
	while (i)
		write(1, &buffer[--i], 1);
}

int	main(void)
{
	int	tab[] = {2,3,4,5};
	int	length = 4;
	
	ft_foreach(tab, length, ft_putnbr);
	return (0);
}
*/
