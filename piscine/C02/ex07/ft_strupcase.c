/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbruck <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 19:33:20 by sbruck            #+#    #+#             */
/*   Updated: 2024/07/17 16:09:23 by sbruck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strupcase(char *str)
{
	char	*start;

	start = str;
	while (*str)
	{
		if (*str >= 'a' && *str <= 'z')
			*str = *str - 32;
		str++;
	}
	return (start);
}
/*
#include <stdio.h>

char *ft_strupcase(char *str);

int main(void)
{
    char str1[] = "Hello World!";
    char str2[] = "42 School";
    char str3[] = "all lowercase";

    printf("str1: %s -> ", str1);
    printf("%s\n", ft_strupcase(str1));
    printf("str1: %s -> ", str2);
    printf("%s\n", ft_strupcase(str2));
    printf("str1: %s -> ", str3);
    printf("%s\n", ft_strupcase(str3));
   
    return 0;
}
*/
