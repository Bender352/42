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

char    *get_next_line(int fd)
{
    static t_list  *list;

    list = malloc(sizeof(t_list));
    if(!(list))
        return (NULL);
    read_into_nodes(fd, &list);
    while (list->next)
    {
       // printf("%s", list->content);
       // printf("\n");
        list = list->next;
    }
    if(list->next)
        return list->content;
    return (NULL);
}

void    read_into_nodes(int fd, t_list **list)
{
    char    *buf;
    char    *temp_buf;
    int     j;
    int     i;

    buf = NULL;
    if(fd < 0 || BUFF_SIZE < 0 || read (fd, buf, 0) < 0)
        return;
    if(!(buf = malloc(sizeof(char) * BUFF_SIZE + 1)))
        return;
    if(!(temp_buf = malloc(sizeof(char) * BUFF_SIZE + 1)))
        return;
    (*list)->line_len = read(fd, buf, BUFF_SIZE);
    buf[(*list)->line_len] = '\0';
    j = 0;
    i = 0;
    while(i < BUFF_SIZE)
    {
        if (buf[i] == '\n' || buf[i] == '\0')
        {   
            temp_buf[i] = '\0';
            ft_lstadd_back(list, ft_lstnew(temp_buf));
            i++;
            j = 0;
        }
        temp_buf[i] = buf[i];
        i++;
        j++;
    }
}
