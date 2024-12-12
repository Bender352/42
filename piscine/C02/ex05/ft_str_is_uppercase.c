/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbruck <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 19:17:55 by sbruck            #+#    #+#             */
/*   Updated: 2024/07/17 16:09:54 by sbruck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_uppercase(char *str)
{
	while (*str)
	{
		if (*str >= 'A' && *str <= 'Z')
			str++;
		else
			return (0);
	}
	return (1);
}
/*
#include <stdio.h>

int	ft_str_is_uppercase(char *str);

int	main(void)
{
	char	str1[] = "HELLO";
	char	str2[] = "tesT";
	char	str3[] = "Hello World!";
	char	str4[] = "H2elei";
	
	printf("String 1 -HELLO- :%s -> %d \n", str1, ft_str_is_uppercase(str1)); 
	printf("String 1 -tesT- :%s -> %d \n", str2, ft_str_is_uppercase(str2)); 
	printf("String 1 -Hello !- :%s -> %d \n", str3, ft_str_is_uppercase(str3)); 
	printf("String 1 -H2elei- :%s -> %d \n", str4, ft_str_is_uppercase(str4)); 
}
*/
