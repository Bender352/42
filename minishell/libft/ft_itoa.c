/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knjaloun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 11:43:32 by knjaloun          #+#    #+#             */
/*   Updated: 2024/10/28 13:38:38 by knjaloun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_spcasemanager(int *n, char *result)
{
	if (*n == -2147483648)
	{
		ft_strlcpy(result, "-2147483648", 12);
		return (1);
	}
	if (*n == 0)
	{
		ft_strlcpy(result, "0", 2);
		return (1);
	}
	if (*n < 0)
	{
		result[0] = '-';
		*n *= -1;
	}
	return (0);
}

static int	ft_getnumlen(int n)
{
	int	len;

	len = 0;
	if (n == 0)
	{
		return (1);
	}
	if (n < 0)
		len++;
	while (n != 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*result;
	int		len;
	int		index;

	len = ft_getnumlen(n);
	index = len;
	result = malloc(sizeof(char) * (len + 1));
	if (result == NULL)
	{
		return (NULL);
	}
	result[index] = '\0';
	index--;
	if (ft_spcasemanager(&n, result) == 1)
		return (result);
	while (n != 0)
	{
		result[index] = (n % 10) + '0';
		n /= 10;
		index--;
	}
	return (result);
}
