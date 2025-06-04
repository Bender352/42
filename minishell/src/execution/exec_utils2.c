/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevinnjaloung <kevinnjaloung@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 15:42:10 by kevin-njalo       #+#    #+#             */
/*   Updated: 2025/05/28 21:58:18 by kevinnjalou      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minishell.h"

void	free_heredock(t_redir *infile)
{
	unlink(infile->heredock);
	free(infile->heredock);
	infile->heredock = NULL;
}

int	open_infile(t_redir *infile)
{
	int	fd;

	fd = -1;
	if (!infile)
		return (-1);
	if (infile->type == HERE_DOCK)
	{
		if (infile->heredock)
			fd = open(infile->heredock, O_RDONLY, 0644);
	}
	else
	{
		if (infile->file)
			fd = open(infile->file, O_RDONLY, 0644);
	}
	return (fd);
}

int	free_child(char **envp, t_command *cmd)
{
	if (cmd->exec[0] == '\0' && cmd->args[0][0] == '\0')
	{
		free_envp(envp);
		g_exit_signal = 0;
		return (1);
	}
	return (0);
}

void	close_all(int *fd, int *prev_fd, t_command *cmd)
{
	close_fds(fd, prev_fd, cmd);
	check_closefd(cmd, fd, prev_fd);
}

void	wait_and_clean(int i, t_command *head, pid_t *pids)
{
	wait_for_children(pids, i);
	cleanup_heredocs(head);
}
