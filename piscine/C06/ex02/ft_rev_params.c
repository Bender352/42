/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbruck <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 18:03:11 by sbruck            #+#    #+#             */
/*   Updated: 2024/07/28 16:52:14 by sbruck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char *c);

int	main(int ac, char **argv)
{
	int	i;

	i = 1;
	while (ac != 1)
	{
		ft_putchar(argv[ac - 1]);
		ac--;
	}
	return (0);
}

void	ft_putchar(char *c)
{
	int		i;
	char	d;

	d = '\n';
	i = 0;
	while (c[i] != '\0')
	{
		write(1, &c[i], 1);
		i++;
	}
	write(1, &d, 1);
}
