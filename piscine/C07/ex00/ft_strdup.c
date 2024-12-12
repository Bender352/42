/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbruck <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 14:58:16 by sbruck            #+#    #+#             */
/*   Updated: 2024/07/27 14:58:18 by sbruck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_len_str(char *c);

char	*ft_strdup(char *src)
{
	char	*c;
	int		len_src;
	int		i;

	len_src = ft_len_str(src);
	c = malloc(sizeof(char) * len_src + 1);
	i = 0;
	while (src[i])
	{
		c[i] = src[i];
		i++;
	}
	c[i] = '\0';
	return (c);
}

int	ft_len_str(char *c)
{
	int	i;

	i = 0;
	while (c[i])
		i++;
	return (i);
}
