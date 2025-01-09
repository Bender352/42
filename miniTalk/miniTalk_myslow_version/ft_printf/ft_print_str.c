/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbruck <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 18:50:49 by sbruck            #+#    #+#             */
/*   Updated: 2024/11/09 18:50:51 by sbruck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_str(char *str, size_t *count)
{
	size_t	i;

	i = 0;
	if (str == NULL)
	{
		ft_print_str("(null)", count);
		return ;
	}
	while (str[i])
	{
		ft_put_char(str[i], count);
		i++;
	}
	return ;
}
