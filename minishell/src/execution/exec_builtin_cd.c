/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_builtin_cd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevinnjaloung <kevinnjaloung@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 14:30:04 by sbruck            #+#    #+#             */
/*   Updated: 2025/05/29 23:23:54 by kevinnjalou      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minishell.h"

int	update_oldpwd(t_env **env, char *oldpwd)
{
	t_env	*current_node;

	current_node = *env;
	if (!current_node)
		return (1);
	while (current_node && ft_cmp(current_node->name, "OLDPWD") != 1)
		current_node = current_node->next;
	if (!current_node)
	{
		add_env_end(*env, "OLDPWD", oldpwd, 0);
		free(oldpwd);
		return (0);
	}
	if (current_node->value)
		free(current_node->value);
	current_node->value = oldpwd;
	return (0);
}

int	update_pwd(t_env **env)
{
	char	*cwd;
	t_env	*current_node;

	current_node = *env;
	if (!current_node)
		return (1);
	while (current_node && ft_cmp(current_node->name, "PWD") != 1)
		current_node = current_node->next;
	if (!current_node)
	{
		perror("Error: PWD not found in env.");
		return (1);
	}
	cwd = getcwd(NULL, 0);
	if (!cwd)
	{
		perror("getcwd");
		return (1);
	}
	if (current_node->value)
		free(current_node->value);
	current_node->value = cwd;
	return (0);
}

int	do_error(t_command *cmd, char *msg, int i, t_cd_builtin *cd)
{
	if (i == 0)
	{
		printf("%s\n", msg);
	}
	else if (i == 1)
	{
		printf("cd: %s: No such file or directory\n", cmd->args[1]);
	}
	if (cd->cwd)
	{
		free(cd->cwd);
		cd->cwd = NULL;
	}
	g_exit_signal = 1;
	return (1);
}

int	do_chdir(char *target, t_command *cmd)
{
	if (chdir(target) != 0)
	{
		perror("cd");
		free(cmd);
		cmd = NULL;
		return (1);
	}
	return (0);
}

int	builtin_cd(t_echo_data *data, t_fd fd)
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
			handle_cd_redir(data, fd, data->infile_error);
			if (data->just_redir == 0)
				builtin_cd2(data->env, data->head);
			exit(0);
		}
		else
			store_pid(data->pid, data->index, pid);
		if (data->head->next || data->infile_error == 1)
			return (0);
	}
	builtin_cd2(data->env, data->head);
	return (0);
}
