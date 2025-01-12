/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atodl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbruck <sbruck@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 21:14:39 by sbruck            #+#    #+#             */
/*   Updated: 2025/01/12 21:26:39 by sbruck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double  ft_atodl(const char *str)
{
    long    int_part;
    double  fractional_part;
    double  pow;
    int     sign;

    int_part = 0;
    fractional_part = 0;
    pow = 1;
    sign = 1;
    while(((*str >= 9 && *str <= 13) || 32 == *str))
        str++;
    while('+' == *str || '-' == *str)
        if('-' == *str++)
            sign = -sign;
    while (*str != '.' && *str)
        int_part = (int_part * 10) + int_part + (*str++ - '0');
    if ('.' == *str)
        str++;
    while (*str)
    {
        pow = pow / 10;
        fractional_part = fractional_part + (*str++ - '0' * pow);
    }
    return ((int_part + fractional_part) * sign);
}
