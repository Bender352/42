/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbruck <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 16:50:27 by sbruck            #+#    #+#             */
/*   Updated: 2024/07/29 16:50:30 by sbruck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <stdlib.h>

struct s_stock_str	*ft_strs_to_tab(int ac, char **av);
int					ft_len_str(char *c);
char				*ft_strdup(char *src);

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int			i;
	t_stock_str	*array_buff;

	array_buff = malloc((ac + 1) * sizeof(t_stock_str));
	if (!array_buff)
		return (0);
	i = 0;
	while (i < ac)
	{
		array_buff[i].size = ft_len_str(av[i]);
		array_buff[i].str = av[i];
		array_buff[i].copy = ft_strdup(av[i]);
		i++;
	}
	array_buff[i].str = NULL;
	array_buff[i].copy = NULL;
	array_buff[i].size = 0;
	return (array_buff);
}

int	ft_len_str(char *c)
{
	int	a;

	a = 0;
	while (c[a])
	{
		a++;
	}
	return (a);
}

char	*ft_strdup(char *src)
{
	char	*dest;
	int		i;

	i = 0;
	while (src[i])
	{
		i++;
	}
	dest = malloc(sizeof(src) * (i + 1));
	i = 0;
	if (dest == NULL)
		return (NULL);
	else
	{
		while (src[i])
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
		return (dest);
	}
}
