/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_builtin_export_3.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevinnjaloung <kevinnjaloung@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 16:41:16 by sbruck            #+#    #+#             */
/*   Updated: 2025/05/29 23:34:07 by kevinnjalou      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minishell.h"

int	invalid_export_value(t_command *cmd, int *i, t_env **env)
{
	if (cmd->args[*i][0] == '=')
	{
		printf("export: %s : not a valid identifier\n", cmd->args[*i]);
		g_exit_signal = 1;
		(*i)++;
		return (1);
	}
	if (!has_equal(cmd->args[*i]))
	{
		if (!env_exits(*env, cmd->args[*i]))
		{
			add_env_end(*env, cmd->args[*i], "", 1);
		}
		(*i)++;
		return (1);
	}
	return (0);
}

void	free_export(char **name, char **str)
{
	free_split(name);
	free(*str);
}

int	ft_hasnovalue(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] != ' ' && s[i] != '\t')
			return (0);
		i++;
	}
	write(2, "export: not valid in this context:\n", 36);
	return (1);
}

int	finish_dock(pid_t pid, int fd)
{
	int	status;

	signal(SIGINT, SIG_IGN);
	waitpid(pid, &status, 0);
	if (WIFSIGNALED(status) && WTERMSIG(status) == SIGINT)
	{
		g_exit_signal = 130;
		close(fd);
		return (1);
	}
	close(fd);
	return (0);
}
