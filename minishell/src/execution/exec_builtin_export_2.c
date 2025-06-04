/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_builtin_export_2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevinnjaloung <kevinnjaloung@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 16:41:16 by sbruck            #+#    #+#             */
/*   Updated: 2025/05/29 23:47:17 by kevinnjalou      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minishell.h"

void	free_split(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	env_overwrite(t_env *env, char *name, char *data)
{
	while (!ft_cmp(env->name, name))
	{
		env = env->next;
	}
	free(env->value);
	env->value = ft_strdup(data);
	env->env_hide = 0;
}

int	env_exits(t_env *env, char *name)
{
	while (env)
	{
		if (ft_cmp(env->name, name))
			return (1);
		env = env->next;
	}
	return (0);
}

void	export_empty_args_case(t_env *env)
{
	int		i;
	char	**envp;

	i = 0;
	envp = build_envp(env);
	selection_sort(envp);
	while (envp[i] != NULL)
	{
		printf("export %s\n", envp[i]);
		i++;
	}
	free_envp(envp);
}

int	export_error(t_command *cmd, t_env *env, t_echo_data *data, t_fd fd)
{
	pid_t	pid;
	int		status;

	pid = fork();
	if (pid == 0)
	{
		signal(SIGQUIT, SIG_DFL);
		signal(SIGINT, SIG_DFL);
		handle_pipefd(data->sh->cmd, fd.prev_fd, fd.fd);
		if (handle_infile(data->sh->cmd, 0) || handle_outfile(data->sh->cmd))
		{
			g_exit_signal = 1;
			exit(1);
		}
		if (cmd->args[1] == NULL)
			export_empty_args_case(env);
		g_exit_signal = 0;
		exit(0);
	}
	else
		waitpid(pid, &status, 0);
	if (cmd->args[1] != NULL && !ft_hasnovalue(cmd->args[1]))
		return (0);
	return (1);
}
