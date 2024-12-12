/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbruck <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 16:58:04 by sbruck            #+#    #+#             */
/*   Updated: 2024/07/17 16:58:06 by sbruck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	ft_check_length(char *dest);

char	*ft_strcat(char *dest, char *src)
{
	int	len_dest;
	int	len_src;
	int	i;

	len_src = 0;
	len_src = ft_check_length(src);
	len_dest = ft_check_length(dest);
	i = 0;
	while (src[i] != '\0')
	{
		dest[len_dest + i] = src[i];
		i++;
	}
	dest[len_dest + i] = '\0';
	return (dest);
}

int	ft_check_length(char *dest)
{
	int	len_dest;

	len_dest = 0;
	while (dest[len_dest] != '\0')
	{
		len_dest++;
	}
	return (len_dest);
}
/*
#include <stdio.h>

int	main(void)
{
	char *src;
	char dest[35] = "ABC D";
	
	src = "feg";
	printf("Concatinate %s and %s to %s", src, dest, ft_strcat(dest, src));
}
*/
