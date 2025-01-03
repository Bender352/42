/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbruck <sbruck@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 19:03:56 by sbruck            #+#    #+#             */
/*   Updated: 2025/01/03 19:16:39 by sbruck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

int main (int arg, char **argv)
{
    int pid;
    size_t  i;

    if (arg != 3)
    {
        ft_printf("%s", "not the right input format");
    }
    i = 0;
    pid = ft_atoi(argv[1]);
    while (argv[2][i])
    {
        send_bit(pid, argv[2][i]);
        i++;
    }
}

void    send_bit(int pid, int i)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if ((i & (0x01 << bit)) != 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(100);
		bit++;
	}
}
