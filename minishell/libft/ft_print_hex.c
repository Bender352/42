/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knjaloun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 13:07:22 by knjaloun          #+#    #+#             */
/*   Updated: 2024/11/25 15:41:42 by knjaloun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_hex_len(unsigned	int num)
{
	int	count;

	count = 0;
	while (num != 0)
	{
		count++;
		num = num / 16;
	}
	return (count);
}

void	ft_printhex_recursive(unsigned int num, const char *base)
{
	if (num == 0)
		return ;
	ft_printhex_recursive(num / 16, base);
	write(1, &base[num % 16], 1);
}

int	ft_printf_hex(unsigned int num, short isupper)
{
	if (num == 0)
	{
		write (1, "0", 1);
		return (1);
	}
	if (isupper == 0)
		ft_printhex_recursive(num, "0123456789abcdef");
	else
		ft_printhex_recursive(num, "0123456789ABCDEF");
	return (ft_hex_len(num));
}
