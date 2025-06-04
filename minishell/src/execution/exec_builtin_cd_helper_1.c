/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_builtin_cd_helper_1.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevinnjaloung <kevinnjaloung@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 19:43:49 by sbruck            #+#    #+#             */
/*   Updated: 2025/05/29 23:23:32 by kevinnjalou      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minishell.h"

void	init_cd_struct(t_cd_builtin *cd, t_command *cmd)
{
	cd->cwd = ft_calloc(PATH_MAX, sizeof(char));
	if (!cd->cwd)
		return ;
	if (!getcwd(cd->cwd, PATH_MAX))
	{
		perror("getcwd");
		free(cd->cwd);
		return ;
	}
	cd->args = cmd->args;
	cd->target = NULL;
}

int	builtin_cd2(t_env **env, t_command *cmd)
{
	t_cd_builtin	cd;

	init_cd_struct(&cd, cmd);
	if (!cd.args[1])
	{
		cd.target = get_env_value("HOME", *env);
		if (!cd.target)
			return (do_error(cmd, "cd: HOME not set.", 0, &cd));
	}
	else if (strcmp(cd.args[1], "-") == 0)
		cd.target = get_env_value("OLDPWD", *env);
	else
		cd.target = cd.args[1];
	if (cd.args[2])
		return (do_error(cmd, "cd: too many arguments.", 0, &cd));
	cd.old_pwd_path = get_env_value("PWD", *env);
	if (chdir(cd.target) == -1)
		return (do_error(cmd, cd.target, 1, &cd));
	update_oldpwd(env, ft_strdup(cd.old_pwd_path));
	update_pwd(env);
	free(cd.cwd);
	g_exit_signal = 0;
	return (0);
}

void	handle_cd_redir(t_echo_data *data, t_fd fd, int invalid_infile)
{
	signal(SIGQUIT, SIG_DFL);
	signal(SIGINT, SIG_DFL);
	handle_pipefd(data->sh->cmd, fd.prev_fd, fd.fd);
	if (invalid_infile == 1 || try_open_outfile(data->sh->cmd->outfile) == 1)
	{
		g_exit_signal = 1;
		exit(1);
	}
	g_exit_signal = 0;
}
