/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbruck <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 19:02:45 by sbruck            #+#    #+#             */
/*   Updated: 2024/07/12 19:05:30 by sbruck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(int *a, int *b)
{
	int	swap;

	swap = *a;
	*a = *b;
	*b = swap;
}
/*
#include <stdio.h>

int main(void)
{
	int		a;
	int		b;
	int		*ptra;
	int		*ptrb;

	a = 1;
	b = 2;
	
	printf("a : %d, b : %d\n", a, b);
	
	ptra = &a;
	ptrb = &b;

	ft_swap(ptra, ptrb);

	printf("a : %d, b : %d\n", a, b);
}
*/
