/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbruck <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 11:18:00 by sbruck            #+#    #+#             */
/*   Updated: 2024/07/17 16:57:04 by sbruck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2)
{
	int	b;

	while (*s1 && *s2)
	{
		b = *s1 - *s2;
		if (b != 0)
			return (b);
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}
/*
#include <stdio.h>

int	main(void)
{
	char	*a;
	char	*b;
	char	*c;
	
	a = "Hello";
	b = "Hello";
	c = "Don't panic!";
	
	printf ("Compaire A to B it should be 0: %d\n", ft_strcmp(a, b));
	printf ("Compaire A to C. The difference is :%d\n", ft_strcmp(a, c));
	printf ("Compaire B to C. The difference is :%d\n", ft_strcmp(c, b));
}
*/
