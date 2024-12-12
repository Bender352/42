/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbruck <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 13:56:46 by sbruck            #+#    #+#             */
/*   Updated: 2024/08/01 13:56:50 by sbruck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		is_valid_base(char *base);
int		ft_atoi_base(char *nbr, char *base);
int		get_value_from_char(char c, char *base);
char	*ft_convert_base(char *nbr, char *base_from, char *base_to);
int		handle_whitespace_and_sign(char *nbr, int *sign);
int		get_base_length(char *base);

int	is_valid_base(char *base)
{
	int	i;
	int	j;

	if (!base || !base[0] || !base[1])
		return (0);
	i = 0;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-' || base[i] <= ' ' || base[i] > '~')
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	get_value_from_char(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}
/*
int	ft_atoi_base(char *nbr, char *base)
{
	int	i;
	int	value;
	int	sign;
	int	result;
	int	base_length;

	i = 0;
	sign = 1;
	result = 0;
	while (nbr[i] == ' ' || (nbr[i] >= 9 && nbr[i] <= 13))
		i++;
	if (nbr[i] == '-')
	{
		sign = -1;
		i++;
	}
	if (nbr[i] == '+')
	{
		sign = 1;
		i++;
	}
	base_length = 0;
	while (base[base_length])
		base_length++;
	while (nbr[i])
	{
		value = get_value_from_char(nbr[i], base);
		if (value == -1)
			break ;
		result = result * base_length + value;
		i++;
	}
	return (result * sign);
}
*/

int	get_base_length(char *base)
{
	int	length;

	length = 0;
	while (base[length])
		length++;
	return (length);
}

int	handle_whitespace_and_sign(char *nbr, int *sign)
{
	int	i;

	i = 0;
	while (nbr[i] == ' ' || (nbr[i] >= 9 && nbr[i] <= 13))
		i++;
	if (nbr[i] == '-')
	{
		*sign = -1;
		i++;
	}
	else if (nbr[i] == '+')
	{
		*sign = 1;
		i++;
	}
	return (i);
}

int	ft_atoi_base(char *nbr, char *base)
{
	int	i;
	int	value;
	int	sign;
	int	result;
	int	base_length;

	sign = 1;
	result = 0;
	i = handle_whitespace_and_sign(nbr, &sign);
	base_length = get_base_length(base);
	while (nbr[i])
	{
		value = get_value_from_char(nbr[i], base);
		if (value == -1)
			break ;
		result = result * base_length + value;
		i++;
	}
	return (result * sign);
}
