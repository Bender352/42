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
# define BUFF_SIZE 100
# endif

typedef struct s_list
{
    int             line_len;
    char            *content;
    struct s_list   *next;
} t_list;

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

char    *get_next_line(int fd);
void    read_into_nodes(int fd, t_list **list);
void	ft_lstadd_back(t_list **lst, t_list *new);
t_list	*ft_lstnew(void *content);
t_list  *ft_lstlast(t_list *list);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup(const char *s);
size_t	ft_strlen(const char *s);

# endif