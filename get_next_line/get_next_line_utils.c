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

	printf("list->stach address: %p\n", list->stach);
	list->stach_len = (int)ft_strlen(list->stach);
	temp_buf = ft_strdup(list->stach);
	free(list->stach);
	list->stach = malloc(sizeof(char) * list->stach_len + 2);
	if(!(list->stach))
		return;
	i = 0;
	while ((int)i < list->stach_len + 2)
	{
		if ((int)i < list->stach_len)
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
	printf("list->stach address: %p\n", s);
	length = ft_strlen((char *)s);
	if (start >= length)
		return (ft_strdup(""));
	if (start + len > length)
		len = length - start;
	result = (char *) malloc(sizeof(char) * (len + 1));
	if (result == NULL)
	{
		free(result);
		return (NULL);
	}
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

	if(s == NULL)
		return (0);

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

	if(!s)
		return(0);
	size_s = 0;
	while (s[size_s])
		size_s++;
	buff = malloc(size_s * (sizeof(char)) + 1);
	if (buff == NULL)
	{	
		free(buff);
		return (NULL);
	}
	i = 0;
	while (i <= size_s)
	{
		buff[i] = s[i];
		i++;
	}
	return (buff);
}
