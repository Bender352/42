/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbruck <sbruck@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 09:35:02 by sbruck            #+#    #+#             */
/*   Updated: 2025/01/14 09:49:20 by sbruck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
    t_list  list;

    read_into_list(&list, fd);
}

void    read_into_list(t_list *list, int fd)
{
    char    *buff;

    buf = malloc(BUFFER_SIZE + 1);
    if (buf == NULL)
        return;
    buf = rea
}