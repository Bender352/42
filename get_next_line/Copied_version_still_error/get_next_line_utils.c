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

int	ft_strchr(char *str, char c)
{
	size_t	i;
	
	i = 0;
	if (str == NULL)
		return (0);
	while (str[i])
	{
		if(str[i++] == c)
			return (1);
		else
			return (0);	
	}
	if (str[i] == c)
		return (1);
	return (0);
}

char	*ft_strjoin(char *str1, char *str2)
{
	size_t	len_str1;
	size_t	len_str2;
	char	*tem;
	size_t	i;
	size_t	j;
	
	len_str1 = ft_strlen(str1);
	len_str2 = ft_strlen(str2);
	i = 0;
	j = 0;
	tem = malloc(sizeof(char) * (len_str1 + len_str2 + 1));
	if (!tem)
		return (NULL);
	while (str1[i])
	{
		tem[i] = str1[i];
		i++;
	}
	while (str2[j])
	{
		tem[i + j] = str2[j];
		j++;
	}
	tem[i + j] = '\0';
	return (tem);
}

char	*ft_strdup(char *str)
{
	size_t	i;
	size_t 	len;
	char	*tem;
	
	i = 0;
	len = ft_strlen(str);
	tem = calloc(len + 1, sizeof(char));
	if (!tem)
		return (NULL);
	while (str[i])
	{
		tem[i] = str[i];
		i++;	
	}
	tem[i] = '\0';
	return (tem);
}

size_t	ft_strlen(char *str)
{
	size_t	len;
	
	len = 0;
	while (str[len])
		len++;	
	return (len);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	if (count != 0 && size > SIZE_MAX / count)
		return (NULL);
	ptr = malloc(count * size);
	if (!ptr)
		return (NULL);
	ft_memset(ptr, 0, count * size);
	return (ptr);
}

void	*ft_memset(void *s, int c, size_t n)
{
	while (n--)
		((unsigned char *)s)[n] = (unsigned char) c;
	return (s);
}
