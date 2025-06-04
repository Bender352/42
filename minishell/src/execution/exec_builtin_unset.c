/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_builtin_unset.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevinnjaloung <kevinnjaloung@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 14:18:32 by sbruck            #+#    #+#             */
/*   Updated: 2025/05/29 23:30:42 by kevinnjalou      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minishell.h"

static int	builtin_unset_helper(t_env **env, t_env *curr, t_command *cmd,
		int i)
{
	t_env	*prev;

	prev = NULL;
	while (curr)
	{
		if (strcmp(curr->name, cmd->args[i]) == 0)
		{
			if (prev == NULL)
				*env = curr->next;
			else
				prev->next = curr->next;
			free(curr->name);
			free(curr->value);
			free(curr);
			g_exit_signal = 0;
			return (0);
		}
		prev = curr;
		curr = curr->next;
	}
	g_exit_signal = 0;
	return (0);
}

int	builtin_unset2(t_command *cmd, t_env **env)
{
	t_env	*curr;
	int		return_value;
	int		i;

	curr = *env;
	i = 1;
	if (cmd->infile || cmd->outfile)
		if (cmd->args[1] == NULL)
			return (1);
	return_value = 0;
	while (cmd->args[i])
	{
		return_value = builtin_unset_helper(env, curr, cmd, i);
		i++;
	}
	return (return_value);
}

void	builtin_unset(t_command *cmd, t_fd fd, t_env **env, t_echo_data *data)
{
	pid_t	pid;
	int		has_fork;

	has_fork = 0;
	if (try_open_outfile(cmd->outfile) || try_open_infile(cmd->infile))
		return ;
	if (data->head->next)
		has_fork = 1;
	if (has_fork == 0)
	{
		builtin_unset2(cmd, env);
		return ;
	}
	pid = fork();
	if (pid == 0)
	{
		handle_pipefd(cmd, fd.prev_fd, fd.fd);
		builtin_unset2(cmd, env);
		exit(0);
	}
	else
	{
		signal(SIGINT, SIG_IGN);
		store_pid(data->pid, data->index, pid);
	}
}
