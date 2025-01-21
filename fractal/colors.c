/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbruck <sbruck@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 18:39:49 by sbruck            #+#    #+#             */
/*   Updated: 2025/01/21 18:40:38 by sbruck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int     set_color(int t, int r, int g, int b)
{
    return (t << 24 | r << 16 | g << 8 | b);
}

int     get_t(int trgb)
{
    return ((trgb >> 24) & 0xFF);
}

int     get_r(int trgb)
{
    return ((trgb >> 16) & 0xFF);
}

int     get_g(int trgb)
{
    return ((trgb >> 8) & 0xFF);
}

int     get_b(int trgb)
{
    return (trgb & 0xFF);
}