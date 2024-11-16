/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbruck <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 18:50:21 by sbruck            #+#    #+#             */
/*   Updated: 2024/11/09 18:50:26 by sbruck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	va_list	args;
	size_t	i;
	size_t	count_char;

	count_char = 0;
	i = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			ft_handle_variables(str[i + 1], args, &count_char);
			i++;
		}
		else
			ft_put_char(str[i], &count_char);
		i++;
	}
	va_end(args);
	return (count_char);
}

void	ft_handle_variables(const char c, va_list args, size_t *count_char)
{
	if (c == 'd' || c == 'i')
		ft_handle_num(ft_base_num(), va_arg(args, int), count_char);
	if (c == 's')
		ft_print_str(va_arg(args, char *), count_char);
	if (c == 'c')
		ft_put_char(va_arg(args, int), count_char);
	if (c == 'p')
		ft_ptr_add(va_arg(args, void *), count_char);
	if (c == 'u')
		ft_handle_num(ft_base_num(), (unsigned int)va_arg(args, int),
			count_char);
	if (c == 'x')
		ft_handle_num(ft_base_hex('l'),
			(unsigned int)va_arg(args, long long int),
			count_char);
	if (c == 'X')
		ft_handle_num(ft_base_hex('u'),
			(unsigned int)va_arg(args, long long int),
			count_char);
	if (c == '%')
		ft_put_char('%', count_char);
}
