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

	list->stach_len = (int)ft_strlen(list->stach);
	//printf("stach leng is : %d\n",list->stach_len);
	//printf("Stach buffer is: %s", list->stach);
	temp_buf = ft_strdup(list->stach);
	//printf("TEMP buffer is: %s", temp_buf);
	free(list->stach);
	list->stach = malloc(sizeof(char) * list->stach_len + 2);
	if(!(list->stach))
	{
		del_list_content(list->stach);
		return;
	}
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

void	del_list_content(char *str)
{
	size_t	i;
	size_t	j;

	i = ft_strlen(str);
	j = 0;
	while (j < i)
	{
		str[j] = '\0';
		j++;
	}
	free(str);
}

void	ft_cpy_stach_to_buf(t_list *list)
{
	int	i;

	i = 0;
	list->stach_len = ft_strlen(list->stach);
	if(!(list->buf = malloc(BUFF_SIZE + list->stach_len + 1)))
	{
		del_list_content(list->buf);
		return;
	}
	while (i < list->stach_len)
	{
		list->buf[i] = list->stach[i];
		i++;
	}
	list->buf_len = ft_strlen(list->buf);
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
