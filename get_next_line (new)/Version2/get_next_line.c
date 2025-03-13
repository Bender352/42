/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbruck <sbruck@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 16:25:00 by sbruck            #+#    #+#             */
/*   Updated: 2025/03/13 12:29:56 by sbruck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
[Start]  
  │  
  ▼  
Check FD/BUFFER_SIZE validity → [Invalid? → Return NULL]  
  │  
  ▼  
Read data via `read()` → Append to static buffer  
  │  
  ▼  
Check for `\n` in buffer → [Found? → Split line/remainder]  
  │                             │  
  ▼                             ▼  
[No]                        [Yes → Return line]  
  │  
  ▼  
Repeat until `\n` or EOF 
*/


char    *get_next_line(size_t fd)
{
    static char     *buffer;
    char            *read_buf;

    if(fd < 2 && fd > 1024)
        return NULL;
    read_buf = create_buffer(BUFFER_SIZE);
    if(!read_buf)
        return NULL;
    while (!contains_EOL(buffer))
	{
		read(fd, read_buf, BUFFER_SIZE);
		buffer = append_to_buf(buffer, read_buf, 0);
	}
	if (contains_EOL(buffer) != 0)
		return (build_retrun_str(buffer, contains_EOL(buffer)));
	else
		return NULL;
}

char	*build_retrun_str(char *buf, int eol_pos)
{
    int	i;
    char    *return_buf;

    return_buf = create_buffer(eol_pos + 1);
	if(!return_buf)
		return NULL;
	i = 0;
	while (i <= eol_pos)
	{
		return_buf[i] = buf[i];
		i++;
	}
	append_to_buf(0, buf, eol_pos);
	return return_buf;
}

char    *create_buffer(int size)
{
    char    *buf;
    int		i;

	i = 0;
    buf = malloc(size + 1);
	if (!buf)
		return NULL;
	while(i < size + 1)
		buf[i++] = 0;
	return buf;
}

char	*append_to_buf(char *buffer, char *read_buf, int pos)
{
    char    *temp;
	char	*temp_2;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (pos)						//only adds next line to buffer or \0 when EOF
		temp_2 = read_buf + pos + 1;
	else
		temp_2 = read_buf;
    temp = create_buffer(len_str(buffer) + len_str(temp_2) + 1);
	if(!temp)
		return NULL;
	while(buffer && buffer[i])
	{
		temp[i] = buffer[i];
		i++;
	}
	while (read_buf && read_buf[j])
	{
		temp[i + j] = read_buf[j];
		j++;
	}
	free_stuff(buffer, read_buf, 0);
	return (temp);
}

void	free_stuff(char *buf1, char *buf2, char *buf3)
{
	if (buf1)
	 free(buf1);
	if (buf2)
	 free(buf2);
	if (buf3)
	 free(buf3);
}

int	len_str(char *str)
{
    int i;

    i = 0;
    if (!str)
        return 0;
    while(str[i])
    {
        i++;
    }
    return i;
}

int	contains_EOL(char *str)
{
    int i;

    i = 0;
    if (!str)
        return 0;
    while (str[i])
    {
        if (str[i] == '\n')
            return(i);
        else if (str[i] == '\0')
            return(i);
        i++;
    }
    return (0);
}

int	main()
{
	
	int	fd;

	fd = open("text.txt", O_RDONLY);

	while(1)
	{
		char	*buf = get_next_line(fd);
		if (buf[0] == 0)
			break;
		else
			printf("%s", buf);
	}
	return 0;
}