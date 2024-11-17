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
	if(!list->stach)
		list
}
void	get_substr_until_nl(t_list *list)
{
	const char	*start;
	size_t		size_substr;
	char		*substr;

	*start = list->content;
	while (list->content && list->content != '\n')
	{
		list->content++;
	}
	size_substr = list->content - start;
	if(!(substr = malloc(sizeof(char) * size_substr + 1)))
		return;
	


}

void	ft_strncpy(t_list list, int len)
{
	char	*buf;
	size_t	i;
	size_t	buf_len;

	buf_len = ft_str_len(list.stach) + len + 1;
	if(!(buf = malloc(sizeof(char) * (buf_len))))
		return;
	i = 0;
	while (i < buf_len)


	if(!stach)
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
