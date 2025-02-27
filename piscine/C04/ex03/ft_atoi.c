/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbruck <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 16:48:23 by sbruck            #+#    #+#             */
/*   Updated: 2024/07/21 16:48:25 by sbruck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

bool	contains_character(char c, char *str)
{
	while (*str)
	{
		if (*str == c)
			return (true);
		str++;
	}
	return (false);
}

bool	is_space(char c)
{
	return (contains_character(c, "\t\n\v\f\r "));
}

bool	is_operator(char c)
{
	return (contains_character(c, "+-"));
}

bool	is_number(char c)
{
	return (c >= '0' && c <= '9');
}

int	ft_atoi(char *str)
{
	int	sign;
	int	result;

	result = 0;
	sign = 1;
	while (is_space(*str))
		str++;
	while (is_operator(*str))
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (is_number(*str))
	{
		result *= 10;
		result += *str - '0';
		str++;
	}
	return (result * sign);
}
/*
#include <stdio.h>

int	main(void)
{
	int	i;
	
	i = ft_atoi("     --++-5784443&)&j65");
	printf("Print digit from string: %d\n", i);
	return (0);
}
*/
