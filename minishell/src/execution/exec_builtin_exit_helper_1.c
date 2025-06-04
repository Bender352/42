/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_builtin_exit_helper_1.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knjaloun <knjaloun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 16:28:36 by sbruck            #+#    #+#             */
/*   Updated: 2025/05/29 19:23:08 by knjaloun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minishell.h"

int	try_open_infile(t_redir *infile)
{
	int	fd;

	fd = -1;
	while (infile)
	{
		if (infile->type == REDIR_IN)
		{
			fd = open(infile->file, O_RDONLY);
			if (fd == -1)
			{
				write(2, infile->file, ft_strlen(infile->file));
				write(2, ": No such file or directory\n", 29);
				return (1);
			}
			close(fd);
		}
		infile = infile->next;
	}
	return (0);
}

int	try_open_outfile(t_redir *outfile)
{
	int	fd;

	while (outfile)
	{
		if (outfile->type == REDIR_OUT_A)
			fd = open(outfile->file, O_WRONLY | O_APPEND | O_CREAT, 0644);
		else
			fd = open(outfile->file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (fd == -1)
		{
			perror(outfile->file);
			return (1);
		}
		close(fd);
		outfile = outfile->next;
	}
	return (0);
}

int	builtin_exit2(t_minishell *sh, int infork)
{
	int		status;
	char	**args;

	status = 0;
	args = sh->cmd->args;
	if (args[1])
	{
		if (args[2])
		{
			ft_putendl_fd("exit: too many arguments", STDERR_FILENO);
			status = 2;
			g_exit_signal = 2;
			return (2);
		}
		else if (!is_numeric_exit(args[1]))
		{
			ft_putendl_fd("exit: numeric argument required", STDERR_FILENO);
			status = 2;
		}
		else
			status = ft_atoi(args[1]);
	}
	if (infork == 0)
		ft_putendl_fd("exit", STDOUT_FILENO);
	return (helper_space_function(sh, status));
}

void	handle_exit_redir(t_echo_data *data, t_fd fd, int invalid_infile)
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
