/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_toascii.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knjaloun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 15:22:07 by knjaloun          #+#    #+#             */
/*   Updated: 2024/11/21 16:26:04 by knjaloun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

static char	*ft_special_case(char	*str, int num)
{
	if (num == 0)
	{
		ft_strcpy(str, "0");
		return (str);
	}
	else
	{
		ft_strcpy(str, "-2147483648");
		return (str);
	}
}

static int	ft_getnumlen(int num)
{
	int	count;

	count = 0;
	if (num == 0)
		return (1);
	if (num < 0)
		count++;
	while (num != 0)
	{
		num = num / 10;
		count++;
	}
	return (count);
}

char	*ft_convert_toascii(int num)
{
	char	*str;
	int		i;

	str = malloc(sizeof(char) * (ft_getnumlen(num) + 1));
	if (num == 0 || num == -2147483648)
		return (ft_special_case(str, num));
	i = ft_getnumlen(num);
	str[i] = '\0';
	i--;
	if (num < 0)
	{
		str[0] = '-';
		num = num * (-1);
	}
	while (num != 0)
	{
		str[i] = (num % 10) + '0';
		num = num / 10;
		i--;
	}
	return (str);
}
