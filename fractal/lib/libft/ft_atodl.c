/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atodl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbruck <sbruck@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 22:44:28 by sbruck            #+#    #+#             */
/*   Updated: 2025/01/13 22:44:30 by sbruck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

double ft_atodl(const char *str)
{
    long int_part = 0;
    double fractional_part = 0.0;
    double pow = 1.0;
    int sign = 1;

    while (((*str >= 9 && *str <= 13) || 32 == *str))
        str++;
    while ('+' == *str || '-' == *str)
        if ('-' == *str++)
            sign = -sign;
    while (*str != '.' && *str)
        int_part = (int_part * 10) + (*str++ - '0');
    if (*str == '.')
        str++;
    while (*str)
    {
        fractional_part = fractional_part * 10 + (*str++ - '0');
        pow *= 10;
    }
    return (int_part + fractional_part / pow) * sign;
}
/*
#include <stdio.h>
#include <stdlib.h>
int main(int ac, char **av)
{
    if (ac > 1)
    {
        printf("Input: %s\n", av[1]);
        printf("Converted value: %f\n", ft_atodl(av[1]));
    }
    else
    {
        printf("No input provided.\n");
    }

    return 0;
}
*/
