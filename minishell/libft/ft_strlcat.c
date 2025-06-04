/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knjaloun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 16:16:02 by knjaloun          #+#    #+#             */
/*   Updated: 2024/10/28 17:54:12 by knjaloun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dstlen;
	size_t	srclen;
	size_t	to_copy ;
	size_t	index_src;

	dstlen = ft_strlen(dst);
	srclen = ft_strlen(src);
	to_copy = size - dstlen - 1;
	index_src = 0;
	if (size <= dstlen)
	{
		return (size + srclen);
	}
	while (src[index_src] != '\0' && index_src < to_copy)
	{
		dst[dstlen + index_src] = src[index_src];
		index_src++;
	}
	dst[dstlen + index_src] = '\0';
	return (dstlen + srclen);
}
/*
size_t     ft_strlen(const char *s)
{
        int     index;
        int     count;

        index = 0;
        count = 0;
        while (s[index] != '\0')
        {
                count++;
                index++;
        }
        return (count);
}

int main ()
{
	char dest[30];
	memset(dest, 0, 30);
	printf("%i", strlcat(dest, "AAAAAAAAA", 0));
}
*/
