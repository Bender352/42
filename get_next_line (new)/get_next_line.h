/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbruck <sbruck@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 08:27:34 by sbruck            #+#    #+#             */
/*   Updated: 2025/01/21 08:27:34 by sbruck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

    # include <stdio.h>
    # include <stdlib.h>
    # include <fcntl.h>
    # include <unistd.h>

    #define BUFFER_SIZE 42

    int     len_str(char *str);
    void    free_stuff(char *str1, char *str2, char *str3);
    int     check_for_nl (char *str);
    char    *add_to_rest(char *rest, char *str);
    char    *get_next_line(int fd);
#endif