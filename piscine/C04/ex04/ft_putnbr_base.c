/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbruck <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 13:51:23 by sbruck            #+#    #+#             */
/*   Updated: 2024/07/22 13:51:25 by sbruck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_in_base(char c, char *base)
{
	while (*base)
		if (c == *base++)
			return (1);
	return (0);
}

void	ft_print(unsigned int n, char *base, unsigned int size)
{
	if (n > size - 1)
	{
		ft_print(n / size, base, size);
		n %= size;
	}
	ft_putchar(base[n]);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	size;

	size = -1;
	while (base[++size])
		if (base[size] == '+' || base[size] == '-' || base[size] == ' '
			|| ft_in_base(base[size], base + size + 1)
			|| (base[size] >= 9 && base[size] <= 13))
			return ;
	if (size < 2)
		return ;
	if (nbr < 0)
	{
		ft_putchar('-');
		ft_print(-nbr, base, size);
	}
	else
		ft_print(nbr, base, size);
}
/*
int	main(void)
{
	char *base = "eritughdnxmv4780321";
	int nbr = 22;
	ft_putnbr_base(nbr, base);
	ft_putchar('\n');
	return (0);
}
*/
