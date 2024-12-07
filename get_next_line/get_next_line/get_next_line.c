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
		{
			buffer = ft_strdup(temp);
			//free_stuff(&temp);
		}
		else
			buffer = ft_strjoin(buffer, temp);
		if (!buffer)
			return (free_stuff(&temp), free_stuff(&buffer), NULL);
	}
	free_stuff(&temp);
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*ret_line;
	char		*temp;
	int			i;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (free_stuff(&buffer), NULL);
	buffer = get_joined_buffer(buffer, fd);
	if (!buffer)
		return (free_stuff(&buffer), NULL);
	i = 0;
	while (buffer[i] != '\n' && buffer[i])
		i++;
	if (buffer[i] == '\n')
		i++;
	ret_line = ft_substr(buffer, 0, i);
	temp = ft_substr(buffer, i, ft_strlen(buffer) - i);
	free_stuff(&buffer);
	buffer = temp;
	if(!buffer)
		free_stuff(&buffer);
	return (ret_line);
}

void	free_stuff(char **stuf)
{
	if (!(*stuf))
		free(*stuf);
	(*stuf) = NULL;
}
