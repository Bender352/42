/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_base10.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knjaloun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 16:29:24 by knjaloun          #+#    #+#             */
/*   Updated: 2024/11/21 17:09:43 by knjaloun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int	ft_print_base10(int num)
{
	char	*str;
	int		count;

	str = ft_convert_toascii(num);
	count = ft_strlen(str);
	ft_print_str(str, 1);
	free(str);
	str = NULL;
	return (count);
}
