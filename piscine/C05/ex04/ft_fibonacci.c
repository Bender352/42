/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbruck <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 16:58:37 by sbruck            #+#    #+#             */
/*   Updated: 2024/07/24 16:58:41 by sbruck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_fibonacci(int index)
{
	if (index < 0)
		return (-1);
	else if (index == 0)
		return (0);
	else if (index == 1)
		return (1);
	else if (index == 2)
		return (1);
	else if (index > 2)
		return (ft_fibonacci(index - 2) + ft_fibonacci(index - 1));
	else
		return (0);
}
/*
unsigned long ft_fibonacci(unsigned long index)
{
	if (index < 0)
		return (0);
	else if (index == 0)
		return (1);
	else if (index == 1)
		return (1);
	else if (index > 1)
		return (ft_fibonacci(index - 2) + ft_fibonacci(index - 1));
	else
		return (0);
}

unsigned long ft_fibonacci_1(unsigned long index)
{
	int	a;
	int	b;
	int	c;

	a = 0;
	b = 1;
	c = 0;	
	
	if (index < 0)
		return (0);
	while (index)
	{
		c = a + b;
		a = b;
		b = c;
		index--;
	}
	return (c);
}

#include <stdio.h>

int	 main(void)
{
	int	i = 5;
	printf("Fibonacci_1 of lu is %d", i);
	printf("%d\n", ft_fibonacci(i));
	return (0);
}
*/
