/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbruck <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 13:14:13 by sbruck            #+#    #+#             */
/*   Updated: 2024/07/20 12:37:58 by sbruck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	res;

	i = 0;
	res = 0;
	while (src[res])
		res++;
	if (size < 1)
		return (res);
	while (src[i] && i < size - 1)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (res);
}
/*
#include <stdio.h>


int main(void)
{
    char src[] = "Hello World!"; // Source string
    char dest[30]; // Ensure dest is large enough to hold src

    // Use ft_strlcpy to copy up to 10 characters from src to dest
    unsigned int a = ft_strlcpy(dest, src, 9);

    // Print the original source string
    printf("Source: %s\n", src);

    // Print the copied destination string
    printf("Destination: %s\n", dest);
    
    // Print the copied destination string
    printf("Lenght of src: %d\n", a);

    return (0);
}
*/
