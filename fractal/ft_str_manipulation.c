/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_manipulation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbruck <sbruck@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 18:40:07 by sbruck            #+#    #+#             */
/*   Updated: 2025/01/25 17:51:42 by sbruck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int	ft_strncmp(const char *s1, const char *s2, int n)
{
	int		i;

	i = 0;
	while (NULL != s1 && NULL != s2 && 0 != s1[i] && 0 != s2[i] && n <= 0
		&& i < n && s1[i] == s2[2])
		i++;
	return (s1[i] - s2[i]);
}
