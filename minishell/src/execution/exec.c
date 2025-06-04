/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knjaloun <knjaloun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 22:52:41 by kevinnjalou       #+#    #+#             */
/*   Updated: 2025/05/29 19:11:17 by knjaloun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minishell.h"

static t_echo_data	*init_echo_data(pid_t *pids, t_env **env, int *i,
		t_command *head)
{
	t_echo_data	*data;

	data = malloc(sizeof(t_echo_data));
	if (!data)
		return (NULL);
	data->env = env;
	data->pid = pids;
	data->index = i;
	data->head = head;
	return (data);
}

static void	finish_execution(int i, t_fd fd, t_echo_data *data)
{
	wait_and_clean(i, data->head, data->pid);
	close_all(fd.fd, fd.prev_fd, data->head);
	check_last_command(data->head);
	data->sh->cmd = data->head;
	free(data);
	signal(SIGINT, sigint_handler);
}

static int	fst_process(t_fd *fd, int *i, t_echo_data *data)
{
	if (data->sh->cmd->next)
	{
		if (pipe(fd->fd) == -1)
		{
			perror("pipe");
			free(data);
			return (1);
		}
	}
	if (is_buildin(data->sh->cmd->exec))
	{
		exec_builtin(data, *fd);
		data->pid[(*i)++] = -1;
		close_all(fd->fd, fd->prev_fd, data->sh->cmd);
	}
	return (0);
}

static void	update_loop(t_command **cmd, t_echo_data *data)
{
	*cmd = (*cmd)->next;
	data->sh->cmd = *cmd;
}

void	start_execution(t_env **env, int i, t_minishell *sh)
{
	t_fd		fd;
	pid_t		pids[1024];
	t_command	*head;
	pid_t		pid;
	t_echo_data	*data;

	if (init_start_exec(&sh->cmd, &head, &fd, *env) == 1)
		return ;
	data = init_echo_data(pids, env, &i, sh->cmd);
	data->sh = sh;
	while (sh->cmd)
	{
		if (fst_process(&fd, &i, data) == 1)
			return ;
		else if (!is_buildin(sh->cmd->exec))
		{
			pid = fork();
			if (pid == 0)
				exec_child(sh->cmd, fd.prev_fd, fd.fd, *env);
			after_child(&fd, &i, pid, data);
		}
		update_loop(&sh->cmd, data);
	}
	finish_execution(i, fd, data);
}
