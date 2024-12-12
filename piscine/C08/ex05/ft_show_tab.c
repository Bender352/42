/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbruck <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 18:23:00 by sbruck            #+#    #+#             */
/*   Updated: 2024/07/29 18:23:02 by sbruck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <unistd.h>

void	ft_show_tab(struct s_stock_str *par);
void	ft_putchar(char *c);
void	ft_putint(int i);

void	ft_show_tab(struct s_stock_str *par)
{
	int	i;

	i = 0;
	while (par->str != NULL)
	{
		ft_putint(par->size);
		ft_putchar(par->str);
		ft_putchar(par->copy);
		par++;
	}
}

void	ft_putchar(char *c)
{
	int	i;

	i = 0;
	while (c[i])
	{
		write(1, &c[i], 1);
		i++;
	}
	write(1, "\n", 1);
}

void	ft_putint(int i)
{
	int		a;
	char	c[60];

	a = 0;
	while (i / 10)
	{
		if (i < 10)
			c[a] = i + '0';
		else
		{
			c[a] = i % 10 + '0';
			i = i / 10;
		}
		a++;
	}
	c[a] = '\0';
	ft_putchar(c);
}
/*
int	main(void)
{
	t_stock_str	t[5];

	
	t[0].size = 5;
	t[0].str = "Hello";
	t[1].size = 4;
	t[1].str = "Abcd";
	t[2].size = 3;
	t[2].str = "Ola";
	t[3].size = 5;
	t[3].str = "Moien";
	t[4].size = 13;
	t[4].str = "Don't Panic!";
	
	
	ft_show_tab(t);
	return (0);
}
*/
