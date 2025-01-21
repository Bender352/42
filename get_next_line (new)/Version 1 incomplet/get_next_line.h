/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbruck <sbruck@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 23:19:40 by sbruck            #+#    #+#             */
/*   Updated: 2025/01/14 18:41:35 by sbruck           ###   ########.fr       */
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
    int     flag_nl;
    int     flag_eof;
    int     start_sub;
    int     stop_sub;
    int     fd;
    struct s_list  *next;
}   t_list;


t_list   *new_node();
void    add_node(t_list **list, int nl, int eof, char *buf);

void    delete_first_node (t_list **list);
char    *merge_str (char *str, char *new);
size_t  len_str(char *str);
void    read_into_list(t_list **list, int fd);

char    *ft_substr(char *str, int start, int stop);

char	*get_next_line(int fd);

# endif