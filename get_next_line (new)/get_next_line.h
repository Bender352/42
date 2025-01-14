/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbruck <sbruck@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 23:19:40 by sbruck            #+#    #+#             */
/*   Updated: 2025/01/14 09:49:18 by sbruck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stddef.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>


#  define BUFFER_SIZE BUFSIZ

# if BUFFER_SIZE > 9223372036854775806
    # undef BUFFER_SIZE
    # define BUFFER_SIZE 9223372036854775806
# endif

typedef struct s_list
{
    char    *content;
    struct s_list  *next;
}   t_list;

void    new_list(t_list *list);

# endif