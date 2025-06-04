/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knjaloun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 12:23:05 by knjaloun          #+#    #+#             */
/*   Updated: 2024/10/28 17:17:21 by knjaloun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	index;

	index = 0;
	if (n == (size_t)0)
		return (0);
	while (s1[index] == s2[index] && index < n)
	{
		if (s1[index] == '\0' || index + (size_t)1 == n)
		{
			return (0);
		}
		index++;
	}
	return ((unsigned char)s1[index] - (unsigned char)s2[index]);
}
