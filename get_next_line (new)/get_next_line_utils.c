/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbruck <sbruck@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 09:35:11 by sbruck            #+#    #+#             */
/*   Updated: 2025/01/14 12:32:25 by sbruck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_list   *new_list()
{
    t_list  *new_list;

    new_list = malloc(sizeof(t_list));
    if(!new_list)
        return (NULL);
    new_list->content = NULL;
    new_list->next = NULL;
    return (new_list);
}

void    add_node(t_list **list, char* content)
{
    t_list  *new;
    t_list  *current;
    
    if (!list || !content)
        return;
    new = new_list();
    if (!new)
        return;
    new->content = content;
    if (!(*list))
        *list = new;
    else
    {
        current = *list;
        while (current->next)
            current = current->next;
        current->next = new;
    }
}

void    delete_first_node (t_list **list)
{
    t_list  *buf;
   
    buf = *list;
    *list = (*list)->next;
    free(buf->content);
    free((buf));
}

char    *merge_str (char *str, char *new)
{
    size_t  str_len;
    size_t  new_len;
    size_t  i;
    size_t  j;
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
    return (str_return[j] = 0);
}

size_t  len_str(char *str)
{
    size_t  i;

    i = 0;
    while (str[i])
        i++;
    return (i);
}