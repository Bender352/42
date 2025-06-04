/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knjaloun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 13:52:04 by knjaloun          #+#    #+#             */
/*   Updated: 2024/10/23 14:11:11 by knjaloun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*arr;
	size_t				index;

	index = 0;
	arr = (unsigned char *)s;
	while (index < n)
	{
		if (arr[index] == (unsigned char)c)
		{
			return ((void *)arr + index);
		}
		index++;
	}
	return (NULL);
}
