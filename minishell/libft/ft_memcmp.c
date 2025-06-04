/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knjaloun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 14:18:11 by knjaloun          #+#    #+#             */
/*   Updated: 2024/10/23 15:11:53 by knjaloun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*mem1;
	const unsigned char	*mem2;
	size_t				index;	

	index = 0;
	mem1 = (unsigned char *)s1;
	mem2 = (unsigned char *)s2;
	if (n == 0)
		return (0);
	while (mem1[index] == mem2[index])
	{
		if (index + (size_t)1 == n)
		{
			return (0);
		}
		index++;
	}
	return (mem1[index] - mem2[index]);
}
