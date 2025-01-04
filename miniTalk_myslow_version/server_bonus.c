/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbruck <sbruck@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 19:54:44 by sbruck            #+#    #+#             */
/*   Updated: 2025/01/04 17:21:37 by sbruck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server_bonus.h"

void	handle_signal(int sig, siginfo_t *i, void *context)
{
	static int	bit[2] = {0, 32};
	static int	flag_2 = 0;
	static int	client_pid = 0;

	(void)i;
	(void)context;
	bit[1]--;
    if (sig == SIGUSR1)
        bit[0] = (bit[0] << 1) | 1;
    else
	{
        bit[0] = (bit[0] << 1);
	}
	if (bit[1] == 0)
	{
		if (bit[0] == 4)
		{	
			ft_printf("Recieved Message Temrinal");
			flag_2 = 1;
		}
		else if (bit[0] == '\0')
		{
			flag_2 = 0;
			send_bit(client_pid, 1);
			client_pid = 0;
		}

		if (flag_2 == 0)
			client_pid = add_to_client_pid(client_pid, bit[0]);
		else
			ft_printf("%c", bit[0]);

		bit[1] = 32;
		bit[0] = 0;
	}
}
int	add_to_client_pid(int pid, int nbr)
{
	pid = pid * 10;
	pid = pid + nbr;
	ft_printf("print CLIENT PID - %d\n", pid);
	return (pid);
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
void print_char_binary(unsigned char c) 
{
    for (int i = 7; i >= 0; i--) {
        printf("%d", (c >> i) & 1); // Shift and mask each bit
    }
    printf("\n");
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