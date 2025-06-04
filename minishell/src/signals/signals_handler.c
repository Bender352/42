/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals_handler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knjaloun <knjaloun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 16:55:40 by kevin-njalo       #+#    #+#             */
/*   Updated: 2025/05/29 18:14:18 by knjaloun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minishell.h"

void	sigint_handler(int sig)
{
	(void)sig;
	g_exit_signal = 130;
	write(1, "\n", 1);
	if (isatty(STDIN_FILENO))
	{
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
}

void	heredock_signal(void)
{
	signal(SIGINT, heredock_siquit);
	signal(SIGQUIT, SIG_IGN);
}
