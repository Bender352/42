/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_conversion.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knjaloun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 17:17:42 by knjaloun          #+#    #+#             */
/*   Updated: 2024/11/25 15:44:24 by knjaloun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check_conversion(char c, va_list arg)
{
	if (c == 'c')
		return ((char)ft_print_char(va_arg(arg, int), 1));
	if (c == 's')
		return (ft_print_str(va_arg(arg, char *), 1));
	if (c == 'd' || c == 'i')
		return (ft_print_base10(va_arg(arg, int)));
	if (c == 'u')
		return (ft_print_uint(va_arg(arg, unsigned int)));
	if (c == 'p')
		return (ft_printf_ptrhex(va_arg(arg, unsigned long long)));
	if (c == 'x')
		return (ft_printf_hex(va_arg(arg, unsigned int), 0));
	if (c == 'X')
		return (ft_printf_hex(va_arg(arg, unsigned int), 1));
	if (c == '%')
		return (write(1, "%%", 1));
	return (0);
}
