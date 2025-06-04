/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_builtin_exit.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knjaloun <knjaloun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 23:54:30 by sbruck            #+#    #+#             */
/*   Updated: 2025/05/29 19:23:41 by knjaloun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minishell.h"

int	is_numeric_exit(const char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	if (str[0] == '-' || str[0] == '+')
		i++;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

void	free_env(t_env **env)
{
	t_env	*current;
	t_env	*next;

	if (!env || !*env)
		return ;
	current = *env;
	while (current)
	{
		next = current->next;
		if (current->name)
			free(current->name);
		if (current->value)
			free(current->value);
		free(current);
		current = next;
	}
	*env = NULL;
}

int	helper_space_function(t_minishell *sh, int status)
{
	free_all(NULL, &sh->token, &sh->cmd);
	free_env(&sh->env_node);
	exit(status);
	return (status);
}

int	builtin_exit(t_minishell *sh, t_echo_data *data, t_fd fd)
{
	pid_t	pid;

	data->infile_error = try_open_infile(data->sh->cmd->infile);
	data->just_redir = 0;
	if (data->head->next != NULL || (data->sh->cmd->outfile
			|| data->sh->cmd->infile))
	{
		if (!data->head->next && (data->sh->cmd->outfile
				|| data->sh->cmd->infile))
			data->just_redir = 1;
		pid = fork();
		if (pid == 0)
		{
			handle_exit_redir(data, fd, data->infile_error);
			if (data->just_redir == 0)
				builtin_exit2(sh, 1);
			exit(0);
		}
		else
			store_pid(data->pid, data->index, pid);
		if (data->head->next || data->infile_error == 1)
			return (0);
	}
	builtin_exit2(sh, 0);
	return (0);
}
