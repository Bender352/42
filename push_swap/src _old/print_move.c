/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbruck <sbruck@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 12:46:48 by sbruck            #+#    #+#             */
/*   Updated: 2025/02/07 16:49:40 by sbruck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int ft_strcmp(char *s1, char *s2)
{
    size_t i;

    if (!s1 || !s2)
        return (-1); // Return an error code instead of NULL

    i = 0;
    while (s1[i] && s2[i])
    {
        if (s1[i] != s2[i])
            return ((unsigned char)s1[i] - (unsigned char)s2[i]);
        i++;
    }
    return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

void    print_move(char *str)
{
    if (!ft_strcmp(str, "sa"))
        write(1, "sa", 2);
    else if (!ft_strcmp(str, "sb"))
        write(1, "sb", 2);
    else if (!ft_strcmp(str, "ss"))
        write(1, "ss", 2);
    else if (!ft_strcmp(str, "ra"))
        write(1, "ra", 2);
    else if (!ft_strcmp(str, "rb"))
        write(1, "rb", 2);
    else if (!ft_strcmp(str, "rr"))
        write(1, "rr", 2);
    else if (!ft_strcmp(str, "rra"))
        write(1, "rra", 2);
    else if (!ft_strcmp(str, "rrb"))
        write(1, "rrb", 2);
    else if (!ft_strcmp(str, "rrr"))
        write(1, "rrr", 2);
    else if (!ft_strcmp(str, "pa"))
        write(1, "pa", 2);
    else if (!ft_strcmp(str, "pb"))
        write(1, "pb", 2);
    else if (!ft_strcmp(str, "pp"))
        write(1, "pp", 2);
    write (1, "\n", 1);
}
