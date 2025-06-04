/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_helper_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knjaloun <knjaloun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 22:52:41 by kevinnjalou       #+#    #+#             */
/*   Updated: 2025/05/29 19:24:18 by knjaloun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minishell.h"

void	handle_redir(t_command *cmd, int *fd, int *prev_fd)
{
	signal(SIGQUIT, SIG_DFL);
	signal(SIGINT, SIG_DFL);
	handle_pipefd(cmd, prev_fd, fd);
	if (handle_infile(cmd, 0) || handle_outfile(cmd))
	{
		g_exit_signal = 1;
		exit(1);
	}
}

void	exec_child(t_command *cmd, int *prevfd, int *fd, t_env *env)
{
	char	**envp;

	envp = build_envp(env);
	handle_redir(cmd, fd, prevfd);
	if (!cmd->next)
	{
		if (fd[0] != -1)
			close(fd[0]);
		if (fd[1] != -1)
			close(fd[1]);
	}
	if (execve(cmd->exec, cmd->args, envp) == -1)
		handle_execve(cmd, envp);
}

void	store_pid(pid_t *pids, int *i, pid_t pid)
{
	if (pid == -1)
		perror("fork");
	pids[*i] = pid;
	(*i)++;
}

void	wait_for_children(pid_t *pids, int count)
{
	int	j;
	int	status;

	j = 0;
	status = -999;
	while (j < count)
	{
		if (pids[j] > 0)
			waitpid(pids[j], &status, 0);
		if (status != -999)
		{
			if ((status & 0x7F) == 0)
				g_exit_signal = (status >> 8) & 0xFF;
			else
				g_exit_signal = 128 + (status & 0x7F);
		}
		j++;
	}
}

void	check_last_command(t_command *cmd)
{
	while (cmd->next != NULL)
		cmd = cmd->next;
	if ((!is_buildin(cmd->exec) && access(cmd->exec, X_OK) == -1)
		&& (!ft_cmp(cmd->exec, "")))
		g_exit_signal = 127;
}
