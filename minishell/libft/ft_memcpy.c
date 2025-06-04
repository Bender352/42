/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memcpy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knjaloun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 12:00:10 by knjaloun          #+#    #+#             */
/*   Updated: 2024/10/22 14:57:34 by knjaloun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void	*dest, const void *src, size_t n)
{
	const unsigned char	*source;
	unsigned char		*destination;
	size_t				index;

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
