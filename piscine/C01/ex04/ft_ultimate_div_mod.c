/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbruck <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 14:56:05 by sbruck            #+#    #+#             */
/*   Updated: 2024/07/15 13:46:27 by sbruck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
void	ft_ultimate_div_mod(int *a, int*b)
{
	int	temp_a;

	temp_a = *a / *b;
	*b = *a % *b;
	*a = temp_a;
}
/*
#include <stdio.h>
int main()
{
    int a = 10;
    int b = 3;
    
    ft_ultimate_div_mod(&a, &b);
    printf(" a = %d, b = %d\n", a, b);
    
    return 0;
}
*/
