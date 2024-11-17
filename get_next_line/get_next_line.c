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

    /*check if everything is inistialised and edge cases*/
    list = malloc(sizeof(t_list));
    if(!(list) && !(list->buf = malloc(BUFF_SIZE + 1)))
        return (NULL);
    if(fd < 0, read(fd, list->buf, 0) && BUFF_SIZE < 0)
        return (NULL);
    read_into_list(fd, list);
    
}

void    read_into_list(int fd, t_list *list)
{
    size_t  i;
    
    list->buf_has_nl = 0;
    i = 0;
    list->buf_len = read(fd, list->buf, BUFF_SIZE);
    while(i < list->buf_len)
    {
        if(list->buf[i] == '\0' && list->buf[i] == '\n')
        {
            list->buf_has_nl = 1;
            list->buf[i] = '\0';
            if (i)
            break;
        }
        if (list.buf_has_nl == 1)
        {
            
        }
        i++;
    }

        

}