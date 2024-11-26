/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbruck <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 17:55:47 by sbruck            #+#    #+#             */
/*   Updated: 2024/11/10 17:55:49 by sbruck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_joined_buffer(char *buffer, int fd, long buf_size)
{
	char	temp[buf_size + 1];
	long	i;

	i = -1;
	while (++i <= buf_size)
		temp[i] = '\0';
	i = 1;
	while (!ft_strchr(temp, '\n') && i)
	{
		i = read(fd, temp, buf_size);
		if (i < 0 || (!i && !buffer))
			return (NULL);
		temp[i] = '\0';
		if (!buffer)
			buffer = ft_strdup(temp);
		else
			buffer = ft_strjoin(buffer, temp);
		if (!buffer)
			return (NULL);
	}
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*ret_line;
	char		*temp;
	int			i;
	long		buf_size;

	if (BUFFER_SIZE > 100)
		buf_size = 100;
	else
		buf_size = BUFFER_SIZE;
	if (fd < 0 || buf_size < 1 || read(fd, 0, 0))
		return (NULL);
	buffer = get_joined_buffer(buffer, fd, buf_size);
	if (!buffer)
		return (NULL);
	i = 0;
	while (buffer[i] != '\n' && buffer[i])
		i++;
	if (buffer[i] == '\n')
		i++;
	ret_line = ft_substr(buffer, 0, i);
	temp = ft_substr(buffer, i, ft_strlen(buffer) - i);
	free(buffer);
	buffer = temp;
	return (ret_line);
}