/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbruck <sbruck@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 19:21:55 by sbruck            #+#    #+#             */
/*   Updated: 2025/01/04 22:11:41 by sbruck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client_bonus.h"

int	g_response = 0;

void	ft_response(int signum)
{
	if(signum == SIGUSR1)
		ft_printf("ACK");
	g_response = 1;

}

void	ft_send_bit(int pid, int bit)
{
	int	signal;

	if (bit == 1)
		signal = SIGUSR1;
	else
		signal = SIGUSR2;
	if (kill(pid, signal) == -1)
	{
		ft_putstr_fd("Error\n", 2);
		exit(EXIT_FAILURE);
	}
}

void	ft_send_char(int pid, char c)
{
	int	i;

	i = BIT_LEN - 1;
	while (i >= 0)
	{
		ft_send_bit(pid, (c >> i) & 1);
		usleep(400);
		i--;
	}
	while (!g_response)
		;
	g_response = 0;
}

void	ft_send_str(int pid, unsigned char *str)
{
	while (*str)
		ft_send_char(pid, *str++);
	ft_send_char(pid, '\0');
}

int	main(const int argc, char **argv)
{
	pid_t	pid;

	if (argc != 3)
	{
		ft_putstr_fd("Usage: ./client <pid> <string>\n", 2);
		exit(EXIT_FAILURE);
	}
	pid = ft_atoi(argv[1]);
	if (pid <= 0)
	{
		ft_putstr_fd("Invalid PID\n", 2);
		exit(EXIT_FAILURE);
	}
	signal(SIGUSR2, ft_response);
	signal(SIGUSR1, ft_response);
	ft_send_str(pid, (unsigned char *)argv[2]);
	return (0);
}
