/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbruck <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 17:55:47 by sbruck            #+#    #+#             */
/*   Updated: 2024/11/26 15:14:34 by sbruck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_joined_buffer(char *buffer, int fd)
{
	char	*temp;
	long	i;

	i = -1;
	temp = malloc(BUFFER_SIZE + 1);
	if (!temp)
		return (free_stuff(&temp), NULL);
	while (++i <= BUFFER_SIZE)
		temp[i] = '\0';
	i = 1;
	while (!ft_strchr(temp, '\n') && i)
	{
		i = read(fd, temp, BUFFER_SIZE);
		if (i < 0 || (!i && !buffer))
			return (free_stuff(&temp), NULL);
		temp[i] = '\0';
		if (!buffer)
			buffer = ft_strdup(temp);
		else
			buffer = ft_strjoin(buffer, temp);
		if (!buffer)
			return (free_stuff(&temp), NULL);
	}
	return (free_stuff(&temp), buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer[OPEN_MAX];
	char		*ret_line;
	char		*temp;
	int			i;

	if (fd < 0 || BUFFER_SIZE < 1 || fd > OPEN_MAX)
		return (NULL);
	buffer[fd] = get_joined_buffer(buffer[fd], fd);
	if (!buffer[fd])
		return (NULL);
	i = 0;
	while (buffer[fd][i] != '\n' && buffer[fd][i])
		++i;
	if (buffer[fd][i] == '\n')
		++i;
	ret_line = ft_substr(buffer[fd], 0, i);
	temp = ft_substr(buffer[fd], i, ft_strlen(buffer[fd]) - i);
	free(buffer[fd]);
	buffer[fd] = temp;
	return (ret_line);
}

void	free_stuff(char **stuf)
{
	free(*stuf);
	(*stuf) = NULL;
	
}
