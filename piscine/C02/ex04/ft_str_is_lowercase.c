/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbruck <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 19:02:03 by sbruck            #+#    #+#             */
/*   Updated: 2024/07/17 16:10:04 by sbruck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_lowercase(char *str)
{
	while (*str)
	{
		if (*str >= 'a' && *str <= 'z')
			str++;
		else
			return (0);
	}
	return (1);
}
/*
#include <stdio.h>

int	ft_str_is_lowercase(char *str);

int	main(void)
{
	char	str1[] = "hello";
	char	str2[] = "tesT";
	char	str3[] = "Hello World!";
	char	str4[] = "H2elei";
	
	printf("String 1 -hello- :%s -> %d \n", str1, ft_str_is_lowercase(str1)); 
	printf("String 1 -tesT- :%s -> %d \n", str2, ft_str_is_lowercase(str2)); 
	printf("String 1 -Hello !- :%s -> %d \n", str3, ft_str_is_lowercase(str3)); 
	printf("String 1 -H2elei- :%s -> %d \n", str4, ft_str_is_lowercase(str4)); 
}
*/
