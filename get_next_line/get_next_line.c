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
    int     i_from;
    int     i_to;

    buf = NULL;
    if(fd < 0 || BUFF_SIZE < 0 || read (fd, buf, 0) < 0)
        return;
    if(!(buf = malloc(sizeof(char) * BUFF_SIZE + 1)))
        return;
    (*list)->line_len = read(fd, buf, BUFF_SIZE);
    buf[(*list)->line_len] = '\0';
    //printf("TEST \n%s", buf);
    i_from = 0;
    i_to = 0;
    while(buf[i_to])
    {
        if (buf[i_to] == '\n' || buf[i_to] == '\0')
        {   
            char    *test = ft_substr(buf, i_from, i_to - i_from);
            printf("%s\n", test);
            ft_lstadd_back(list, ft_lstnew(test));
            i_from = i_to;
        }
        i_to++;
    }
}