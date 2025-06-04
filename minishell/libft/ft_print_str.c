/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knjaloun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 18:11:53 by knjaloun          #+#    #+#             */
/*   Updated: 2024/11/25 13:12:30 by knjaloun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_strlen(char *s)
{
	char	*start;

	start = s;
	while (*s)
		s++;
	return (s - start);
}

int	ft_print_str(char *s, int fd)
{
	if (s == NULL)
	{
		return (write(fd, "(null)", 6));
	}
	return (write(fd, s, ft_strlen(s)));
}
