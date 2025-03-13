/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbruck <sbruck@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 16:25:19 by sbruck            #+#    #+#             */
/*   Updated: 2025/03/11 08:32:53 by sbruck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stddef.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE BUFSIZ  // Set to BUFSIZ only if not defined.
# elif BUFFER_SIZE > 8192  // Cap BUFFER_SIZE at 8192
#  undef BUFFER_SIZE
#  define BUFFER_SIZE 8192
# endif

char    *get_next_line(size_t fd);
char    *append_to_buf(char *buffer, char *read_buf);
void	free_stuff(char *buf1, char *buf2, char *buf3);
int		len_str(char *str);
int		contains_EOL(char *str);
char    *create_buffer();


#endif