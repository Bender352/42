/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knjaloun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 09:25:29 by knjaloun          #+#    #+#             */
/*   Updated: 2024/11/22 09:25:33 by knjaloun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_getnumlen(unsigned int num)
{
	int	count;

	count = 0;
	if (num == 0)
		return (1);
	while (num != 0)
	{
		num = num / 10;
		count++;
	}
	return (count);
}

char	*ft_uitoa(unsigned int num)
{
	char	*str;
	int		i;

	str = malloc(sizeof(char) * (ft_getnumlen(num) + 1));
	i = ft_getnumlen(num);
	str[i] = '\0';
	i--;
	if (num == 0)
	{
		str[0] = '0';
		return (str);
	}
	while (num != 0)
	{
		str[i] = (num % 10) + '0';
		num = num / 10;
		i--;
	}
	return (str);
}
