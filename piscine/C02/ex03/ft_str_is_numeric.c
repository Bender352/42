/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbruck <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 18:57:40 by sbruck            #+#    #+#             */
/*   Updated: 2024/07/17 16:10:19 by sbruck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_numeric(char *str)
{
	while (*str)
	{
		if (*str >= '0' && *str <= '9')
			str++;
		else
			return (0);
	}
	return (1);
}
/*
#include <stdio.h>

int ft_str_is_numeric(char *str);

int main(void)
{
    char str1[] = "1234567890";
    char str2[] = "1234 567890";
    char str3[] = "1234abc567";

    printf("str1: %s -> %d\n", str1, ft_str_is_numeric(str1)); // Should print 1
    printf("str2: %s -> %d\n", str2, ft_str_is_numeric(str2)); // Should print 0
    printf("str3: %s -> %d\n", str3, ft_str_is_numeric(str3)); // Should print 0

    return 0;
}
*/
