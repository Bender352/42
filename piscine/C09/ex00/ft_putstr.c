/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbruck <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 15:53:56 by sbruck            #+#    #+#             */
/*   Updated: 2024/07/15 13:47:37 by sbruck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str);

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}
/*
int main()
{
    char *message = "Hello, world!\n";
    ft_putstr (message);
    return 0;
}
*/
