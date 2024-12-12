/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbruck <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 17:47:57 by sbruck            #+#    #+#             */
/*   Updated: 2024/07/18 14:40:08 by sbruck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (src[i] != '\0' && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}
/*
#include <stdio.h>
char	*ft_strncpy(char *dest, char *src, unsigned int n);

int main(void)
{
    char src[] = "Hello World!"; // Source string
    char dest[20]; // Ensure dest is large enough to hold src

    // Use ft_strncpy to copy up to 10 characters from src to dest
    ft_strncpy(dest, src, 19);

    // Print the original source string
    printf("Source: %s\n", src);

    // Print the copied destination string
    printf("Destination: %s\n", dest);

    return 0;
}
*/
