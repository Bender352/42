/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_builtin_echo.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevinnjaloung <kevinnjaloung@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 16:28:36 by sbruck            #+#    #+#             */
/*   Updated: 2025/05/28 21:58:05 by kevinnjalou      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minishell.h"

static int	is_n_flag(char *arg)
{
	int	i;
	int	n_flag;

	n_flag = 0;
	i = 0;
	if (arg[i] != '-')
		return (n_flag);
	i++;
	while (arg[i] && arg[i] == 'n')
		i++;
	if (arg[i] == '\0')
		n_flag = 1;
	return (n_flag);
}

void	echo_print(char **args, int n_flag, int i)
{
	if (!args[i])
	{
		if (!n_flag)
			ft_putchar_fd('\n', STDOUT_FILENO);
		return ;
	}
	while (args[i])
	{
		ft_putstr_fd(args[i], STDOUT_FILENO);
		if (args[i + 1])
			ft_putchar_fd(' ', STDOUT_FILENO);
		else if (!args[i + 1] && !n_flag)
			ft_putchar_fd('\n', STDOUT_FILENO);
		i++;
	}
}

void	handle_echo_redir(t_echo_data *data, t_fd fd)
{
	signal(SIGQUIT, SIG_DFL);
	signal(SIGINT, SIG_DFL);
	handle_pipefd(data->sh->cmd, fd.prev_fd, fd.fd);
	if (handle_infile(data->sh->cmd, 0) || handle_outfile(data->sh->cmd))
	{
		g_exit_signal = 1;
		exit(1);
	}
}

int	builtin_echo(t_echo_data *data, t_fd fd)
{
	int		k;
	int		n_flag;
	pid_t	pid;

	n_flag = 0;
	k = 1;
	pid = fork();
	if (pid == 0)
	{
		handle_echo_redir(data, fd);
		while (data->sh->cmd->args[k] && is_n_flag(data->sh->cmd->args[k]))
		{
			n_flag = 1;
			k++;
		}
		echo_print(data->sh->cmd->args, n_flag, k);
		g_exit_signal = 0;
		exit(0);
	}
	else
		store_pid(data->pid, data->index, pid);
	return (EXIT_SUCCESS);
}
