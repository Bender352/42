/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_helper_3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevinnjaloung <kevinnjaloung@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 22:52:41 by kevinnjalou       #+#    #+#             */
/*   Updated: 2025/05/28 21:58:16 by kevinnjalou      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minishell.h"

int	init_start_exec(t_command **cmd, t_command **head, t_fd *fd, t_env *env)
{
	(*head) = (*cmd);
	init_prevfd((*fd).fd, (*fd).prev_fd);
	if (prepare_all_heredocs(*head, env))
		return (1);
	return (0);
}

void	after_child(t_fd *fd, int *i, pid_t pid, t_echo_data *data)
{
	signal(SIGINT, SIG_IGN);
	store_pid(data->pid, i, pid);
	close_all(fd->fd, fd->prev_fd, data->head);
}

void	handle_pipefd(t_command *cmd, int *prevfd, int *fd)
{
	if (prevfd[0] != -1)
	{
		dup2(prevfd[0], STDIN_FILENO);
		close(prevfd[0]);
	}
	if (prevfd[1] != -1)
		close(prevfd[1]);
	if (cmd->next)
	{
		dup2(fd[1], STDOUT_FILENO);
		if (fd[0] != -1)
			close(fd[0]);
		if (fd[1] != -1)
			close(fd[1]);
	}
}
