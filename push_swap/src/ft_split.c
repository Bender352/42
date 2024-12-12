/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbruck <sbruck@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 19:24:06 by sbruck            #+#    #+#             */
/*   Updated: 2024/12/12 20:04:00 by sbruck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

char    **ft_split(char *str, char seperator)
{
    int i;
    int flag;
    int words;

    i = 0;
    flag = 0;
    while (*str && flag == 0)
    {
        if (*str == seperator)
            str++;
        else
            flag == 1;
    }
    words = word_count(str, seperator);
}

int ft_strlen(char *str)
{
    int i;

    i = 0;
    while(str[i])
        i++;
    return (i);
}

int word_count(char *str, char seperator)
{
    int i;
    int words;
    int flag;

    i = 0;
    words = 0;
    flag = 0;
    while (str[i])
    {
        if (str[i] == seperator)
        {
            if (str[i +1] == 32)
            {
                flag = 0;
                i++;
            }
        }
    }
    return (words);
}