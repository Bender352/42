/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knjaloun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 18:01:18 by knjaloun          #+#    #+#             */
/*   Updated: 2024/10/29 16:11:04 by knjaloun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str_sub;
	size_t	total_len;
	size_t	count;

	count = 0;
	total_len = ft_strlen(s);
	if (start >= total_len)
	{
		str_sub = malloc(1);
		str_sub[0] = '\0';
		return (str_sub);
	}
	if (len > total_len - start)
		len = total_len - start;
	str_sub = malloc(len + 1);
	if (!str_sub)
		return (NULL);
	while (count < len)
	{
		str_sub[count] = s[start + count];
		count++;
	}
	str_sub[count] = '\0';
	return (str_sub);
}
/*
size_t	ft_strlen(const char *s)
{
	int	index;
	int	count;

	index = 0;
	count = 0;
	while (s[index] != '\0')
	{
		count++;
		index++;
	}
	return (count);
}

int main()
{
	char *h = ft_substr("tripouille", 100, 1);
	printf("%s",h);
	free(h);
}

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
*/
