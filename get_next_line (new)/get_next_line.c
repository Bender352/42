/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbruck <sbruck@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 18:07:00 by sbruck            #+#    #+#             */
/*   Updated: 2025/03/05 00:07:42 by sbruck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char    *return_nl(char *rest)
{
    char    *buf;

    buf = malloc (len_str(rest) + 1);
    while (*rest)
    {
        if (*rest)
        {
            
        }
    }
    return (buf);
}

int check_for_nl (char *str)
{
    int i;

    i = 0;
    if (NULL == str)
    {
        return (-1);
    }
    while (str[i])
    {
        if ( '\n' == str[i] || '\0' == str[i])
        {
            return (1);
        }
        i++;
    }
    return (0);
}

char    *add_to_rest(char *rest, char *str)
{
    char    *new_str;
    int i;
    int j;

    new_str = malloc (len_str(rest) + BUFFER_SIZE + 1);
    if (!new_str)
        return NULL;
    i = 0;
    j = 0;
    if (rest)
        while (rest[i])
            new_str[i++] = rest[j++];
    if (len_str(str) > 0)
    {
        new_str[i++] = ' ';
        j = 0;
        while (str[j])
            new_str[i++] = str[j++];
    }
    new_str[i] = 0;
    free_stuff (rest, str, 0);
    return (new_str);
}

char *get_next_line(int fd)
{
    static char *rest;
    char        *buf;
    ssize_t     bit_read;

    if (fd < 2 || fd > 1024 || BUFFER_SIZE <= 0)
        return NULL;
    bit_read = read(fd, buf, BUFFER_SIZE);
    rest = add_to_rest (rest, buf); // saves lines because I don't need to check if malloc works. It should return a NULL terminated string of BUFF SIZE.
    if (check_for_nl(rest) > 0)
        return(get_return_string(rest));
    else
        return NULL;
    // TODO  if read gives less then BUFF_SIZE back
}
