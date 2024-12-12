/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbruck <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 17:20:23 by sbruck            #+#    #+#             */
/*   Updated: 2024/07/25 17:20:26 by sbruck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlen(char *str)
{
	unsigned int	len;

	len = 0;
	while (str[len])
	{
		len++;
	}
	return (len);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	len_dest;
	unsigned int	len_src;
	unsigned int	i;
	unsigned int	j;

	len_dest = ft_strlen(dest);
	len_src = ft_strlen(src);
	if (size == 0 || size <= len_dest)
		return (len_src + size);
	i = len_dest;
	j = 0;
	while (src[j] && j < (size - len_dest - 1))
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (len_dest + len_src);
}
/*
#include <stdio.h>

int	main(void)
{
	char	dest[50] = "1337 42";
	char	*src = "Born to code";
	unsigned int	d = 20;
	unsigned int	i; 
	
	printf("Add %s \nto the end of \n%s\ntogether to ",src, dest);
	i = ft_strlcat(dest, src, d);
	printf("\n%s\nand the total lenght will be \n%d\n", dest, i);
	return (0);
}
*/
