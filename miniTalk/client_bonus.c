/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbruck <sbruck@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 19:03:56 by sbruck            #+#    #+#             */
/*   Updated: 2025/01/04 02:29:56 by sbruck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client_bonus.h"

int main (int arg, char **argv)
{
    int server_pid;
    size_t  i;

    if (arg != 3)
    {
        ft_printf("%s", "not the right input format");
    }
    i = 0;
    server_pid = ft_atoi(argv[1]);
    send_pid(server_pid);
    while (argv[2][i])
    {
        send_bit(server_pid, argv[2][i]);
        i++;
    }
    send_bit(server_pid, '\0');
    list_ack();
    return (0);
}

void    send_bit(int server_pid, int i)
{
	int	bit;

	bit = 31;
    while (bit >= 0)
    {
        if ((i >> bit) & 1)
        {
			kill(server_pid, SIGUSR1);
        }
		else
        {
			kill(server_pid, SIGUSR2);
        }
        usleep(500);
		bit--;
	}
}

void    send_pid(int server_pid)
{
	int	bit;
    char    *client_pid;
    int i;

    client_pid = ft_itoa(getpid());
	bit = 31;
    i = 0;
    while (client_pid[i])
    {
        send_bit(server_pid, client_pid[i]);
    }
    send_bit(server_pid, 4);
}
void	handle_signal(int sig, siginfo_t *i, void *context)
{
    (void)i;
	(void)context;
    if (sig == SIGUSR1)
	{
        ft_printf("%s", "ACK");
        exit;
	}
}
void    list_ack()
{
    struct sigaction	s;

    s.sa_sigaction = handle_signal;
    s.sa_flags = SA_SIGINFO;
    sigaction(SIGUSR1, &s, NULL);
    sigaction(SIGUSR2, &s, NULL);
    while (1)
        pause();
    return (0);
}
