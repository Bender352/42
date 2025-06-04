/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_uint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knjaloun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 10:01:03 by knjaloun          #+#    #+#             */
/*   Updated: 2024/11/22 10:22:05 by knjaloun         ###   ########.fr       */
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

int	ft_print_uint(unsigned int num)
{
	char	*str;
	int		count;

	str = ft_uitoa(num);
	count = ft_strlen(str);
	ft_print_str(str, 1);
	free(str);
	return (count);
}
