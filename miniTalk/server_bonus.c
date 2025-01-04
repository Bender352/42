/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbruck <sbruck@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 19:22:35 by sbruck            #+#    #+#             */
/*   Updated: 2025/01/04 21:13:24 by sbruck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server_bonus.h"

void    ft_handle_signal(int signum, siginfo_t *info, void *context)
{
	static int				bits;
	static unsigned char	c;
	static pid_t			pid;

	(void) context;
	if (pid != info->si_pid)
	{
		bits = 0;
		c = 0;
	}
	pid = info->si_pid;
	c = c << 1;
	if (signum == SIGUSR1)
		c = c | 1;
	bits++;
	if (bits == BIT_LEN)
		ft_write_c(&c, &bits, pid);
	kill(pid, SIGUSR2);
}
void	ft_write_c (unsigned char *c, int *bits, pid_t pid)
{
	write(1, c, 1);
	*bits = 0;
	if (*c == '\0')
		kill(pid, SIGUSR1);
	*c = 0;

}

int	main(void)
{
	struct sigaction	action;
	sigset_t			set;

	sigemptyset(&set);
	ft_printf("Server PID: %d\n", getpid());
	action.sa_sigaction = &ft_handle_signal;
	action.sa_flags = SA_SIGINFO;
	action.sa_mask = set;
	sigaction(SIGUSR1, &action, NULL);
	sigaction(SIGUSR2, &action, NULL);
	while (1)
		;
	return (0);
}
