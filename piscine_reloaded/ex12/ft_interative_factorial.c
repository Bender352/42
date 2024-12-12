/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_interative_factorial.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbruck <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 15:07:16 by sbruck            #+#    #+#             */
/*   Updated: 2024/10/18 15:07:19 by sbruck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

int	ft_iterative_factorial(int nb)
{
	int	i;
	int	count;

	i = nb;
	count = 1;
	while (count != nb)
	{
		i = i * count;
		count++;
	}
	return (i);
}
/*
int	main(void)
{
	int	i = 12;
	printf("The factorial of %d is %d", i, ft_iterative_factorial(i));
	return 0;
}*/
