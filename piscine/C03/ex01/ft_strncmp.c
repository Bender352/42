/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbruck <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 16:17:08 by sbruck            #+#    #+#             */
/*   Updated: 2024/07/17 16:57:38 by sbruck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	if (!n)
		return (0);
	i = 0;
	while (i < n && s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	if (i < n)
		return (s1[i] - s2[i]);
	else
		return (0);
}
/*
#include <stdio.h>

int	main(void)
{
	char	*a;
	char	*b;
	char	*c;
	unsigned int	i;
	
	i = 3;
	a = "Hello";
	b = "Helao";
	c = "Don't panic!";
	
	printf ("Compaire A to B it should be 0: %d\n", ft_strncmp(a, b, i));
	printf ("Compaire A to C. The difference is :%d\n", ft_strncmp(a, c, i));
	printf ("Compaire B to C. The difference is :%d\n", ft_strncmp(c, b, i));
}
*/
