/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbruck <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 13:51:38 by sbruck            #+#    #+#             */
/*   Updated: 2024/10/31 13:51:40 by sbruck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	src_len;
	size_t	dst_len_append;
	size_t	i;
	size_t	to_copy;

	src_len = (size_t)ft_strlen((char *)src);
	dst_len_append = (size_t)ft_strlen(dest);
	if (size == 0 && !dest)
		return(src_len);
	if (size <= dst_len_append)
	{
		return (size + src_len);
	}
	to_copy = size - dst_len_append - 1;
	i = 0;
	while (i < to_copy && src[i] != '\0')
	{
		dest[dst_len_append + i] = src[i];
		i++;
	}
	dest[dst_len_append + i] = '\0';
	return (src_len + dst_len_append);
}
