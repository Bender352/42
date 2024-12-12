/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbruck <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 15:08:43 by sbruck            #+#    #+#             */
/*   Updated: 2024/07/23 15:08:45 by sbruck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	i;
	int	num;

	num = 1;
	i = 1;
	if (nb < 0)
		return (0);
	while (i <= nb)
	{
		num = num * i;
		i++;
	}
	return (num);
}
/*
int	main(void)
{
	ft_iterative_factorial(49);
	return (0);
}
*/
