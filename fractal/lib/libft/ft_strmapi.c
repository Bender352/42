/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbruck <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 13:52:18 by sbruck            #+#    #+#             */
/*   Updated: 2024/10/31 13:52:19 by sbruck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*buff;

	i = 0;
	if (s == NULL || f == NULL)
		return (NULL);
	buff = (char *)malloc(sizeof(char) * ft_strlen((char *)s) + 1);
	if (buff == NULL)
		return (NULL);
	while (s[i])
	{
		buff[i] = f(i, s[i]);
		i++;
	}
	buff[i] = '\0';
	return (buff);
}
