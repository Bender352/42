/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptr_add.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbruck <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 18:51:07 by sbruck            #+#    #+#             */
/*   Updated: 2024/11/09 18:51:09 by sbruck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_ptr_add(void *ptr, size_t *count)
{
	if (ptr == NULL)
	{
		ft_print_str("(nil)", count);
		return ;
	}
	ft_print_str("0x", count);
	if ((unsigned long)ptr == ULONG_MAX)
		ft_print_str("ffffffffffffffff", count);
	else
		ft_handle_num(ft_base_hex('l'), (unsigned long int)ptr, count);
	return ;
}
