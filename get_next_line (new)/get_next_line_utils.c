/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbruck <sbruck@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 09:35:11 by sbruck            #+#    #+#             */
/*   Updated: 2025/01/14 18:25:15 by sbruck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_list   *new_node()
{
    t_list  *new_node;

    new_node = malloc(sizeof(t_list));
    if(!new_node)
        return (NULL);
    new_node->content = NULL;
    new_node->next = NULL;
    new_node->flag_eof = 0;
    new_node->flag_nl = 0;
    new_node->start_sub = 0;
    new_node->stop_sub = 0;
    return (new_node);
}

void    add_node(t_list **list, int nl, int eof, char *buf)
{
    t_list  *new;
    t_list  *current;
    
    if (!list)
        return;
    new = new_node();
    if (!new)
        return;
    (*list)->flag_eof = eof;
    (*list)->flag_nl = nl;
    (*list)->content = buf;
    if (1 == eof)
        return;
    current = *list;
    while (current->next)
        current = current->next;
    current->next = new;
}

void    delete_first_node (t_list **list)
{
    t_list  *buf;
   
    if(1 == (*list)->flag_eof)
    {
        free(*list);
    }
    else
    {
        buf = *list;
        *list = (*list)->next;
        free((buf));
    }
}

char    *merge_str (char *str, char *new)
{
    size_t  str_len;
    size_t  new_len;
    int     i;
    int     j;
    char    *str_return;

    str_len = len_str(str);
    new_len = len_str(new);
    str_return = malloc(str_len + new_len + 1);
    if(!str_return)
        return NULL;
    i = -1;
    j = -1;
    while(str[++j])
        str_return[++i] = str[j];
    j = -1;
    while (new[++j])
        str_return[++i] = new[j];
    free (str);
    free (new);
    str_return[j] = 0;
    return (str_return);
}

size_t  len_str(char *str)
{
    size_t  i;

    i = 0;
    while (str[i])
        i++;
    return (i);
}