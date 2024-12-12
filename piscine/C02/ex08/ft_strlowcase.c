/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbruck <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 20:07:07 by sbruck            #+#    #+#             */
/*   Updated: 2024/07/17 16:09:11 by sbruck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strlowcase(char *str)
{
	char	*startpoint;

	startpoint = str;
	while (*str)
	{
		if (*str >= 'A' && *str <= 'Z')
			*str = *str + 32;
		str++;
	}
	return (startpoint);
}
/*
#include <stdio.h>

int main(void)
{
    char str1[] = "Hello World!";
    char str2[] = "42 School";
    char str3[] = "all lowercase";

    printf("str1: %s -> ", str1);
    printf("%s\n", ft_strlowcase(str1));
    printf("str1: %s -> ", str2);
    printf("%s\n", ft_strlowcase(str2));
    printf("str1: %s -> ", str3);
    printf("%s\n", ft_strlowcase(str3));
   
    return 0;
}
*/
