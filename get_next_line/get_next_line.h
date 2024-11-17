/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbruck <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 17:56:21 by sbruck            #+#    #+#             */
/*   Updated: 2024/11/10 17:56:23 by sbruck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE
# define GET_NEXT_LINE

# ifndef BUFF_SIZE
# define BUFF_SIZE 10
# endif

typedef struct s_list
{
    int             read_len;
    int             found_nl_pos;
    char            *buf;
    int             buf_len;
    char            *stach;
    int             stach_len;
} t_list;

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

char    *get_next_line(int fd);
void    read_into_list(int fd, t_list *list);
void	append_to_stach(t_list *list, char c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s);
void	del_list_content(char *str);
void	ft_cpy_stach_to_buf(t_list *list);


# endif