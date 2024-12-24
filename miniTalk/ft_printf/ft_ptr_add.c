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
	ft_handle_numptr(ft_base_hex('l'), (uintptr_t)ptr, count);
}
