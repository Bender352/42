/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_num.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbruck <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 18:50:03 by sbruck            #+#    #+#             */
/*   Updated: 2024/11/09 18:50:05 by sbruck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_handle_num(char *base, long long int i, size_t *count)
{
	int	base_nbr;

	base_nbr = ft_str_len(base);
	if (i < base_nbr && i >= 0)
	{
		ft_put_char(base[i], count);
		return ;
	}
	if (i < 0)
	{
		if (base_nbr == 10)
			ft_put_char('-', count);
		i = i * -1;
	}
	if (i / base_nbr != 0)
		ft_handle_num(base, i / base_nbr, count);
	ft_put_char(base[i % base_nbr], count);
}

void	ft_handle_numptr(char *base, uintptr_t i, size_t *count)
{
	uintptr_t base_nbr;

	base_nbr = ft_str_len(base);
	if (i < base_nbr)
	{
		ft_put_char(base[i], count);
		return ;
	}
	if (i / base_nbr != 0)
		ft_handle_num(base, i / base_nbr, count);
	ft_put_char(base[i % base_nbr], count);
}

