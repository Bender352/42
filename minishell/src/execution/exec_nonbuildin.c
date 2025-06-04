/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_nonbuildin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevinnjaloung <kevinnjaloung@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 15:30:43 by sbruck            #+#    #+#             */
/*   Updated: 2025/05/28 21:58:17 by kevinnjalou      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minishell.h"

int	exec_builtin(t_echo_data *data, t_fd fd)
{
	if (ft_cmp(data->sh->cmd->exec, "echo") == 1)
		builtin_echo(data, fd);
	else if (ft_cmp(data->sh->cmd->exec, "unset") == 1)
		builtin_unset(data->sh->cmd, fd, data->env, data);
	else if (ft_cmp(data->sh->cmd->exec, "env") == 1)
		env_builtin(*data->env, fd, data);
	else if (ft_cmp(data->sh->cmd->exec, "export") == 1)
		builtin_export(data->env, data->sh->cmd, data, fd);
	else if (ft_cmp(data->sh->cmd->exec, "pwd") == 1)
		builtin_pwd(fd, data);
	else if (ft_cmp(data->sh->cmd->exec, "cd") == 1)
		builtin_cd(data, fd);
	else if (ft_cmp(data->sh->cmd->exec, "exit") == 1)
		builtin_exit(data->sh, data, fd);
	return (0);
}

void	close_fds(int *fd, int *prev_fd, t_command *cmd)
{
	if (cmd->next && fd[1] != -1)
	{
		close(fd[1]);
		fd[1] = -1;
	}
	if (prev_fd[0] != -1)
	{
		close(prev_fd[0]);
		prev_fd[0] = -1;
	}
	if (prev_fd[1] != -1)
	{
		close(prev_fd[1]);
		prev_fd[1] = -1;
	}
}

int	prepare_all_heredocs(t_command *cmd, t_env *env)
{
	t_redir	*r;

	while (cmd)
	{
		r = cmd->infile;
		while (r)
		{
			if (r->type == HERE_DOCK && !r->heredock)
			{
				if (handle_heredock(r, r->file, 1, env))
					return (1);
			}
			r = r->next;
		}
		cmd = cmd->next;
	}
	return (0);
}

void	cleanup_heredocs(t_command *cmd)
{
	t_redir	*r;

	while (cmd)
	{
		r = cmd->infile;
		while (r)
		{
			if (r->heredock)
			{
				unlink(r->heredock);
				free(r->heredock);
				r->heredock = NULL;
			}
			r = r->next;
		}
		cmd = cmd->next;
	}
}
