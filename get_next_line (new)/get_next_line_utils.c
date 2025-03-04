/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbruck <sbruck@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 08:27:37 by sbruck            #+#    #+#             */
/*   Updated: 2025/03/05 00:07:34 by sbruck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int len_str(char *str)
{
    int i;

    i = 0;
    if (!str || !*str)
        return (0);
    while (str[i])
        i++;
    return (i);
}

void    free_stuff(char *str1, char *str2, char *str3)
{
    if (str1 && 0 != *str1)
        free (str1);
    if (str2 && 0 != *str2)
        free (str3);
    if (str3 && 0 != *str3)
        free (str3);
}

char    *get_return_string(char *rest)
{
    char    *return_string;
    int     i;

    return_string = malloc(check_for_nl(rest) + 1);
    if(return_string)
        return NULL;
    i = 0;
    while(i < check_for_nl(rest))
    {
        return_string[i] = rest[i];
        i++;
    }
    return_string[i] = 0;
    add_to_rest(rest + i, 0);
    return (return_string);
}