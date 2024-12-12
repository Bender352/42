/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbruck <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 17:49:09 by sbruck            #+#    #+#             */
/*   Updated: 2024/07/28 16:52:27 by sbruck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_putchar(char *c);

int	main(int ac, char **argv)
{
	int	i;

	ac = 3;
	i = 1;
	while (argv[i])
	{
		ft_putchar(argv[i]);
		i++;
	}
	return (0);
}

void	ft_putchar(char *c)
{
	char	d;
	int		i;

	d = '\n';
	i = 0;
	while (c[i] != '\0')
	{
		write(1, &c[i], 1);
		i++;
	}
	write(1, &d, 1);
}
