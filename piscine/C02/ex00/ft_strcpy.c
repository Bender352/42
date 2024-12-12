/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbruck <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 15:26:48 by sbruck            #+#    #+#             */
/*   Updated: 2024/07/18 14:39:47 by sbruck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
/*
#include <stdio.h>

int main(void)
{
    char src[] = "Hello World!"; // Source string
    char dest[50]; // Ensure dest is large enough to hold src

    ft_strcpy(dest, src); // Copy src to dest

    printf("Source: %s\n", src);
    printf("Destination: %s\n", dest);

    return 0;
}
*/
