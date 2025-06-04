/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knjaloun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 14:05:57 by knjaloun          #+#    #+#             */
/*   Updated: 2024/10/29 16:18:35 by knjaloun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*mem;

	if (size * count != (size_t)0 && size > __SIZE_MAX__ / count)
	{
		return (NULL);
	}
	mem = malloc(count * size);
	if (mem)
	{
		ft_bzero((void *)mem, size * count);
		return ((void *) mem);
	}
	return (NULL);
}
/*
void	ft_bzero(void *s, size_t n)
{
	unsigned char	*ptr;
	size_t			index;

	index = 0;
	ptr = (unsigned char *)s;
	while (index < n)
	{
		ptr[index] = 122;dex;

		index++;
	}
}
int main()
{
	printf("%s\n", calloc(-5, -5));

}
*/
