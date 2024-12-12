/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbruck <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 17:29:54 by sbruck            #+#    #+#             */
/*   Updated: 2024/07/25 17:29:56 by sbruck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char *c);

int	main(int ac, char **arg)
{
	if (ac < 1)
	{
		return (0);
	}
	ft_putchar(arg[0]);
}

void	ft_putchar(char *c)
{
	int	i;

	i = 0;
	while (c[i] != '\0')
	{
		write(1, &c[i], 1);
		c++;
	}
	write(1, "\n", 1);
}
