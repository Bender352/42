/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbruck <sbruck@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 19:54:44 by sbruck            #+#    #+#             */
/*   Updated: 2025/01/03 19:29:08 by sbruck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	handle_signal(int sig, siginfo_t *i, void *context)
{
	static unsigned char	bit[2] = {0, 0};

	(void)i;
	(void)context;
    if (sig == SIGUSR1)
        bit[0] |= 1;
    else
        bit[0] |= 0;
	bit[1]++;
	if (bit[1] == 8)
	{
		ft_printf("%c", bit[0]);
		bit[1] = 0;
		bit[0] = 0;
	}
	else
		bit[0] <<= 1;
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