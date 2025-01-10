/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbruck <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 13:53:19 by sbruck            #+#    #+#             */
/*   Updated: 2024/10/31 13:53:21 by sbruck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int		i;
	char	*last_occurrence;

	i = 0;
	last_occurrence = NULL;
	if (!str)
		return (NULL);
	while (str[i] != '\0')
	{
		if (str[i] == (char)c)
		{
			last_occurrence = (char *)(str + i);
		}
		i++;
	}
	if (c == '\0')
	{
		return ((char *)(str + i));
	}
	return (last_occurrence);
}
