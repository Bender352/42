/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbruck <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 17:50:55 by sbruck            #+#    #+#             */
/*   Updated: 2024/07/17 16:08:08 by sbruck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_putchar(char c);

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr_non_printable(char *str)
{
	unsigned char	a;
	char			*hex;

	hex = "0123456789abcdef";
	while (*str != '\0')
	{
		a = *str;
		if (a < 32 || a > 126)
		{
			ft_putchar('\\');
			ft_putchar(hex[a / 16]);
			ft_putchar(hex[a % 16]);
		}
		else
		{
			ft_putchar(*str);
		}
		str++;
	}
}
/*
int	main(void)
{
	char	*c;
	
	c = "Coucou\ntu vas bien ?";
	ft_putstr_non_printable(c);
	return (0);
}
*/
