/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbruck <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 17:56:07 by sbruck            #+#    #+#             */
/*   Updated: 2024/11/10 17:56:08 by sbruck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	append_to_stach(t_list *list, char c)
{
	char	*temp_buf;
	size_t	i;

	list->stach_len = ft_str_len(list->stach_len);
	temp_buf = ft_strdup(list->stach);
	free(list->stach);
	list->stach = malloc(sizeof(char) * list->stach_len + 2);
	i = 0;
	while (i < list->stach_len + 2)
	{
		if (i < list->stach_len)
			list->stach[i] = temp_buf[i];
		else
			list->stach[i] = c;
		i++;
	}
	list->stach[i] = '\0';
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	length;
	char	*result;

	if (!s)
		return (NULL);
	length = ft_strlen((char *)s);
	if (start >= length)
		return (ft_strdup(""));
	if (start + len > length)
		len = length - start;
	result = (char *) malloc(sizeof(char) * (len + 1));
	if (result == NULL)
		return (NULL);
	i = 0;
	while (i < (unsigned int) len)
	{
		result[i] = s[start + i];
		i++;
	}
	result[i] = '\0';
	return (result);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *s)
{
	char	*buff;
	size_t	size_s;
	size_t	i;

	size_s = 0;
	while (s[size_s])
		size_s++;
	buff = malloc(size_s * (sizeof(char)) + 1);
	if (buff == NULL)
		return (NULL);
	i = 0;
	while (i <= size_s)
	{
		buff[i] = s[i];
		i++;
	}
	return (buff);
}
