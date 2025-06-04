/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_builtin_pwd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevinnjaloung <kevinnjaloung@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 14:13:30 by sbruck            #+#    #+#             */
/*   Updated: 2025/05/28 21:58:13 by kevinnjalou      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minishell.h"

static void	handle_pwd_redir(t_fd fd, t_echo_data *data)
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

int	builtin_pwd(t_fd fd, t_echo_data *data)
{
	pid_t	pid;
	char	*pwd;

	pid = fork();
	if (pid == 0)
	{
		handle_pwd_redir(fd, data);
		pwd = getcwd(NULL, 0);
		if (pwd == NULL)
		{
			perror("Error pwd");
			g_exit_signal = 1;
			exit(1);
		}
		printf("%s\n", pwd);
		g_exit_signal = 0;
		free(pwd);
		exit(0);
	}
	else
		store_pid(data->pid, data->index, pid);
	return (0);
}
