/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbruck <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 14:08:40 by sbruck            #+#    #+#             */
/*   Updated: 2024/07/28 14:33:57 by sbruck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*err;
	int	dif;
	int	i;

	i = 0;
	if (min >= max)
	{
		return (0);
	}
	else
	{
		dif = max - min;
		err = (int *)malloc(sizeof(int) * (max - min));
		while (i <= dif - 1)
		{
			err[i] = min + i;
			i++;
		}
		err[i] = '\0';
		return (err);
	}
}
/*
#include <stdio.h>

int	main(void)
{
	int	min;
	int	max;
	int	*back;

	
	min = 4;
	max = 12;
	back = ft_range(min, max);
	
	while(*back)
	{
		printf("%d\n", *back);
		back++;
	}
}
*/
