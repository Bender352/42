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

char	*get_next_line(int fd)
{
	static char	*stach;//left_c
	char		*line;
	char		*buf;
	
	buf = calloc(BUFF_SIZE + 1, sizeof(char));
	if (fd < 0 || BUFF_SIZE <= 0 || read(fd ,0 ,0) < 0)
	{
		free(stach);
		free(buf);
		stach = NULL;
		buf = NULL;
		return (NULL);	
	}
	if (!buf)
		return (NULL);
	line = wr_buf_stach(fd, stach, buf);
	free(buf);
	if (!line)
		return (NULL);
	stach = set_line(line);
	return (line);
}

char	*wr_buf_stach(int fd, char *stach, char *buf)
{
	ssize_t	bytes_read;
	char	*temp;
	
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buf, BUFF_SIZE);
		if (bytes_read == -1)
		{
			free(stach);
			return (NULL);
		}
		if (bytes_read == 0)
			break;
		buf[bytes_read] = '\0';
		if (!stach)
			stach = ft_strdup("");
		temp = stach;
		stach = ft_strjoin(temp, buf);
		free(temp);
		temp = NULL;
		if (ft_strchr(buf, '\0'))
			break;
	}
	return (stach);
}

char	*set_line(char *line)
{
	char    *left_c;
	ssize_t    i;
    
	i = 0;
	while (line[i] != '\n' && line[i] != '\0')
		i++;
	if (line[i] == '\0' || line[1] == '\0')
		return (NULL);
	left_c = ft_substr(line, i + 1, ft_strlen(line) - i);
	if (*left_c == 0)
    {
        free(left_c);
        left_c = NULL;
    }  
	line[i + 1] = 0;
	return (left_c);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*str;

	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		return (malloc(1));
	if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	str = malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (i < len)
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = 0;
	return (str);
}
