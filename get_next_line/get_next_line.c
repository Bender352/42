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
    if (int_list(list, fd) == 0)
        return (NULL);   
    ft_cpy_stach_to_buf(list);
    read_into_list(fd, list);
    return(ft_substr(list->buf, 0, list->found_nl_pos));    
}
/*Den Problem ass an read into list. En muss fir déicht kucken ob nach eppes am buffer ass (2.duechlaaf)

wann jo dann muss en ob \n scannen, wann dat net den fall as dann muss en den Buffer mat read fellen 
Wiederhuelen biss en \n oder \o fennt

Wann en font gouf muss den recht an den Stach geschéckt ginn.
Dann retour iwwer get_next_line to main .*/
void    read_into_list(int fd, t_list *list)
{
    size_t  i;
    
    list->found_nl_pos = 0;
    i = 0;
    list->buf_len = read(fd, list->buf, BUFF_SIZE);
    list->buf[list->buf_len] = '\0';
    while(i < (unsigned int)list->buf_len)
    {
        if(list->buf[i] == '\n')
            list->found_nl_pos = i;
        if (list->found_nl_pos > 0)
        {
            append_to_stach(list, list->buf[i]);
        }
        i++;
    }
}

int    int_list(t_list *list, int fd)
{
    list = malloc(sizeof(t_list));
    if(!(list))
    {
        free(list);
        return (0);
    }
    if(fd < 0 && read(fd, list->buf, 0) && BUFF_SIZE < 0)
    {
        free(list->buf);
        free(list);
        return (0);
    }
    return (1);
}