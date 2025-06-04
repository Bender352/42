/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knjaloun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 11:46:50 by knjaloun          #+#    #+#             */
/*   Updated: 2024/10/31 13:23:09 by knjaloun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	index;
	int		last_occ;

	index = 0;
	last_occ = -1;
	if (c < 0 || c > 255)
		return ((char *)s);
	while (s[index] != '\0')
	{
		if (s[index] == c)
		{
			last_occ = index;
		}
		index++;
	}
	if (c == 0)
	{
		return ((char *)s + index);
	}
	if (last_occ != -1)
		return ((char *)s + last_occ);
	return (NULL);
}
