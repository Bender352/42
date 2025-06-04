/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_builtin_env.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevinnjaloung <kevinnjaloung@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 19:13:08 by sbruck            #+#    #+#             */
/*   Updated: 2025/05/28 21:58:06 by kevinnjalou      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minishell.h"

static void	print_env_error(char *input)
{
	write(2, input, ft_strlen(input));
	write(2, " : no such file or directory\n", 30);
}

int	env_builtin(t_env *env, t_fd fd, t_echo_data *data)
{
	pid_t	pid;

	pid = fork();
	if (pid == 0)
	{
		signal(SIGQUIT, SIG_DFL);
		signal(SIGINT, SIG_DFL);
		handle_pipefd(data->sh->cmd, fd.prev_fd, fd.fd);
		if (handle_infile(data->sh->cmd, 0) || handle_outfile(data->sh->cmd))
		{
			g_exit_signal = 1;
			exit(1);
		}
		if (data->sh->cmd->args[1] == NULL)
			print_env(env);
		else
			print_env_error(data->sh->cmd->args[1]);
		g_exit_signal = 0;
		exit(0);
	}
	else
		store_pid(data->pid, data->index, pid);
	return (0);
}
