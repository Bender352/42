/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbruck <sbruck@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 19:54:44 by sbruck            #+#    #+#             */
/*   Updated: 2025/01/04 01:43:07 by sbruck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	handle_signal(int sig, siginfo_t *i, void *context)
{
	static int	bit[2] = {0, 8};

	(void)i;
	(void)context;
	bit[1]--;
    if (sig == SIGUSR1)
	{
        bit[0] = (bit[0] << 1) | 1;
	}
    else
	{
        bit[0] = (bit[0] << 1);
	}
	if (bit[1] == 0)
	{
		//ft_printf("%c", bit[0]);
		write (1, &bit[0], 1);
		bit[1] = 8;
		bit[0] = 0;
	}
}

void print_char_binary(unsigned char c) 
{
    for (int i = 7; i >= 0; i--) {
        printf("%d", (c >> i) & 1); // Shift and mask each bit
    }
    printf("\n");
}

int	main(void)
{
	struct sigaction	s;

	ft_printf("Server PID : %i\n", getpid());
	s.sa_sigaction = handle_signal;
	s.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &s, NULL);
	sigaction(SIGUSR2, &s, NULL);
	while (1)
		pause();
	return (0);
}
//https://github.com/lai-jia-jing/minitalk/blob/main/server.c