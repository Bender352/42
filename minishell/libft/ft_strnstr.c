/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knjaloun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 15:24:14 by knjaloun          #+#    #+#             */
/*   Updated: 2024/10/23 16:25:36 by knjaloun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	x;
	size_t	y;

	x = 0;
	y = 0;
	if (little[0] == '\0')
		return ((char *) big);
	while (big[y] != '\0' && y < len)
	{
		x = 0;
		while (big[x + y] == little[x] && (x + y) < len)
		{
			if (little[x + 1] == '\0')
				return ((char *) big + y);
			x++;
		}
		y++;
	}
	return (NULL);
}
