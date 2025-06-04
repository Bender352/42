/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_outfile.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevinnjaloung <kevinnjaloung@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 22:27:22 by kevinnjalou       #+#    #+#             */
/*   Updated: 2025/05/28 21:58:22 by kevinnjalou      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minishell.h"

static int	process_intermediate_outfiles(t_redir *outfile, t_redir **final)
{
	int	fd;

	while (outfile->next)
	{
		if (outfile->type == REDIR_OUT_A)
			fd = open(outfile->file, O_WRONLY | O_APPEND | O_CREAT, 0644);
		else
			fd = open(outfile->file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (fd == -1)
		{
			perror(outfile->file);
			return (-1);
		}
		close(fd);
		outfile = outfile->next;
	}
	(*final) = outfile;
	return (0);
}

static int	process_final_outfile(t_redir *outfile)
{
	int	fd;

	if (outfile->type == REDIR_OUT_A)
		fd = open(outfile->file, O_WRONLY | O_APPEND | O_CREAT, 0644);
	else
		fd = open(outfile->file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
	{
		perror(outfile->file);
		return (-1);
	}
	dup2(fd, STDOUT_FILENO);
	close(fd);
	return (0);
}

int	handle_outfile(t_command *cmd)
{
	t_redir	*outfile;
	t_redir	*final;

	if (cmd->outfile == NULL)
		return (0);
	outfile = cmd->outfile;
	final = outfile;
	if (process_intermediate_outfiles(outfile, &final) == -1)
		return (1);
	if (process_final_outfile(final) == -1)
		return (1);
	return (0);
}
