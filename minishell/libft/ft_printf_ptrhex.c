/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ptrhex.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knjaloun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 15:10:10 by knjaloun          #+#    #+#             */
/*   Updated: 2024/11/25 15:42:45 by knjaloun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_getlen(unsigned long long num)
{
	int		count;

	count = 0;
	while (num != 0)
	{
		num = num / 16;
		count ++;
	}
	return (count);
}

void	ft_printhex_rec(unsigned long long ptr, const char *base)
{
	if (ptr == 0)
		return ;
	ft_printhex_rec(ptr / 16, base);
	write (1, &base[ptr % 16], 1);
}

int	ft_printf_ptrhex(unsigned long long ptr)
{
	int		count;

	count = 2;
	if (ptr == 0)
	{
		write (1, "(nil)", 5);
		return (5);
	}
	count += ft_getlen(ptr);
	write(1, "0x", 2);
	ft_printhex_rec(ptr, "0123456789abcdef");
	return (count);
}
