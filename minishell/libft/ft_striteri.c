/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knjaloun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 14:14:29 by knjaloun          #+#    #+#             */
/*   Updated: 2024/10/28 15:00:43 by knjaloun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	char	*p;
	size_t	i;

	i = 0;
	p = s;
	if (s == NULL || f == NULL)
	{
		return ;
	}
	while (s[i] != '\0')
	{
		f(i, p);
		p++;
		i++;
	}
}
