/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbruck <sbruck@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 09:35:02 by sbruck            #+#    #+#             */
/*   Updated: 2025/01/14 18:43:18 by sbruck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
    static t_list   *list;
    char            *buf;

    if (list == NULL)
        list = new_node();
    if (fd < 2 && fd < 1024)
        list->fd = fd;
    else if (1 == list->flag_nl || 1 == list->flag_eof)
    {
        buf = list->content;
        delete_first_node(&list);
        return (buf);
    }
    else
        read_into_list(&list, fd);
    return NULL;
}
static void reset_start_stop(t_list **list)
{
    (*list)->start_sub = len_str ((*list)->content);
    (*list)->stop_sub = len_str ((*list)->content);
}

void    read_into_list(t_list **list, int fd)
{
    char        *buf;
    int         read_bits;
    t_list      *buflist;

    buflist = *list;
    buf = malloc(BUFFER_SIZE + 1);
    if (NULL == buf)
        return;
    read_bits = read(fd, buf, BUFFER_SIZE);
    if(-1 == read_bits)
        return;
    while((*list)->stop_sub < BUFFER_SIZE)
    {
        if ('\n' == buf[buflist->stop_sub])
        {
            add_node(list, 1, 0, ft_substr(buf, buflist->start_sub, buflist->stop_sub));
            buflist->start_sub = buflist->stop_sub;
        }
        else if ('\0' == buf[buflist->stop_sub])
            buflist->flag_eof = 1;
        (*list)->stop_sub++;
    }
    buflist->content = ft_substr(buf, buflist->start_sub, buflist->stop_sub);
    reset_start_stop(list);
    get_next_line((*list)->fd);
}

char    *ft_substr(char *str, int start, int stop)
{
    char    *buf;
    int     i;

    i = 0;
    if (!str || start > stop || stop > len_str (str))
        return NULL;
    buf = malloc (stop - start + 2);
    if (!buf)
        return NULL;
    while (start <= stop)
        buf[i++] = str[start++];
    buf[i] = '\0';
    return (buf);    
}
