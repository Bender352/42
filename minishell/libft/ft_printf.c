/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knjaloun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 17:19:55 by knjaloun          #+#    #+#             */
/*   Updated: 2024/11/18 17:24:13 by knjaloun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		i;
	int		count;

	va_start(args, s);
	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if (s[i] != '%')
			count += ft_print_char(s[i], 1);
		else
		{
			count += ft_check_conversion(s[i + 1], args);
			i++;
		}
		i++;
	}
	va_end(args);
	return (count);
}
