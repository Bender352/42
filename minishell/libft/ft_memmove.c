/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knjaloun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 13:14:59 by knjaloun          #+#    #+#             */
/*   Updated: 2024/10/22 16:10:40 by knjaloun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*destination;
	const unsigned char	*source;
	size_t				index;

	index = 0;
	source = (unsigned char *)src;
	destination = (unsigned char *)dest;
	if (dest == NULL || src == NULL)
		return (NULL);
	if (source < destination && source + n > destination)
	{
		index = n;
		while (index > 0)
		{
			destination[index - 1] = source[index - 1];
			index--;
		}
		return (dest);
	}
	return (ft_memcpy(dest, src, n));
}
/*
void    *ft_memcpy(void *dest, const void *src, size_t n)
{
        unsigned char   *destination;
        const unsigned char     *source;
        size_t                  index;

        index = 0;
        source = (unsigned char *)src;
        destination = (unsigned char *)dest;
	while (index < n)
	{
		destination[index] = source[index];
		index++;

	}
	return (dest);
}
*/
