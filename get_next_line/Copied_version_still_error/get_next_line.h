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
# define BUFF_SIZE 6506
# endif

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdint.h>
#include <limits.h>


char	*get_next_line(int fd);
char	*wr_buf_stach(int fd, char *stach, char *buf);
char	*ft_strdup(char *str);
size_t	ft_strlen(char *str);
void	*ft_calloc(size_t count, size_t size);
void	*ft_memset(void *s, int c, size_t n);
char	*ft_substr(char *s, unsigned int start, size_t len);
char	*set_line(char *line);
char	*ft_strjoin(char *str1, char *str2);
int	ft_strchr(char *str, char c);

# endif
