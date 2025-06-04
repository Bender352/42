/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memset.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knjaloun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 15:22:34 by knjaloun          #+#    #+#             */
/*   Updated: 2024/10/22 11:30:59 by knjaloun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t num)
{
	unsigned char	*ptr;
	unsigned char	value;
	size_t			index;

	ptr = (unsigned char *)s;
	value = (unsigned char)c;
	index = 0;
	while (index < num)
	{
		ptr[index] = value;
		index++;
	}
	return (s);
}
