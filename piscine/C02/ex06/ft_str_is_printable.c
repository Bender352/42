/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbruck <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 19:22:03 by sbruck            #+#    #+#             */
/*   Updated: 2024/07/17 16:09:38 by sbruck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_printable(char *str)
{
	while (*str)
	{
		if (*str >= 32 && *str <= 126)
			str++;
		else
			return (0);
	}
	return (1);
}
/*
#include <stdio.h>

int ft_str_is_printable(char *str);

int main(void)
{
    char str1[] = "Hello World!";
    char str2[] = "Hello\tWorld!";
    char str3[] = "Hello\nWorld!";
    char str4[] = "";

    printf("str1: %s -> %d\n", str1, ft_str_is_printable(str1));
    printf("str2: %s -> %d\n", str2, ft_str_is_printable(str2));
    printf("str3: %s -> %d\n", str3, ft_str_is_printable(str3));
    printf("str4: %s -> %d\n", str4, ft_str_is_printable(str4));

    return 0;
}
*/
