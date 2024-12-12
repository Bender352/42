/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbruck <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 16:04:19 by sbruck            #+#    #+#             */
/*   Updated: 2024/07/23 16:04:20 by sbruck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_factorial(int nb)
{
	if (nb < 0)
		return (0);
	else if (nb > 1)
		return (ft_recursive_factorial(nb - 1) * nb);
	else
		return (1);
}
/*
#include <stdio.h>
int	main(void)
{
	int	nb;
	
	nb = 5;
	printf("Result is: %d\n", ft_recursive_factorial(nb));
}
*/
