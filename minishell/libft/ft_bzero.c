/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bzero.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knjaloun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 10:41:55 by knjaloun          #+#    #+#             */
/*   Updated: 2024/10/22 11:42:33 by knjaloun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*ptr;
	size_t			index;

	index = 0;
	ptr = (unsigned char *)s;
	while (index < n)
	{
		ptr[index] = 0;
		index++;
	}
}
