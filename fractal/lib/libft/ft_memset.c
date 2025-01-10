/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbruck <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 13:48:03 by sbruck            #+#    #+#             */
/*   Updated: 2024/10/31 13:48:05 by sbruck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t len)
{
	size_t	i;
	char	*bloc;

	i = 0;
	bloc = (char *)s;
	while (i < len)
	{
		bloc[i] = (unsigned char)c;
		i++;
	}
	return (s);
}
