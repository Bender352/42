/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_helper_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevinnjaloung <kevinnjaloung@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 22:52:41 by kevinnjalou       #+#    #+#             */
/*   Updated: 2025/05/28 21:58:15 by kevinnjalou      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minishell.h"

void	handle_execve(t_command *cmd, char **envp)
{
	if (ft_cmp(cmd->exec, ""))
	{
		free_envp(envp);
		g_exit_signal = 0;
		exit(0);
	}
	if (access(cmd->exec, R_OK) == -1)
	{
		write(2, cmd->exec, ft_strlen(cmd->exec));
		write(2, " : command not found\n", 22);
	}
	else
		perror(cmd->exec);
	free_envp(envp);
	g_exit_signal = 127;
	exit(127);
}

int	path_exists(t_env *env)
{
	while (env)
	{
		if (ft_cmp(env->name, "PATH"))
			return (1);
		env = env->next;
	}
	return (0);
}

char	*get_exec_name(char *str)
{
	int	i;

	i = ft_strlen(str);
	if (access(str, R_OK) == -1)
		return (ft_strdup(str));
	while (i != 0)
	{
		if (str[i] == '/')
			break ;
		i--;
	}
	return (ft_strdup(str + (i + 1)));
}

void	exec_error(char *str)
{
	char	*exec_name;

	exec_name = get_exec_name(str);
	write(2, exec_name, ft_strlen(exec_name));
	write(2, " : command not found\n", 22);
	free(exec_name);
	g_exit_signal = 127;
	exit(1);
}
