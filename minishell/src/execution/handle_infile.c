/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_infile.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knjaloun <knjaloun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 14:03:46 by kevinnjalou       #+#    #+#             */
/*   Updated: 2025/05/29 19:13:55 by knjaloun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minishell.h"

static int	final_infile_redirect(t_redir *final, int dock)
{
	int	fd;

	if (dock == 1)
		return (0);
	if (final->type == HERE_DOCK)
		fd = open(final->heredock, O_RDONLY);
	else
		fd = open(final->file, O_RDONLY);
	if (fd == -1)
	{
		perror("fd");
		return (1);
	}
	dup2(fd, STDIN_FILENO);
	close(fd);
	return (0);
}

static int	iterate_infiles(t_command *cmd, t_redir **final)
{
	t_redir	*infile;
	t_redir	*prev;
	int		fd;

	infile = cmd->infile;
	prev = infile;
	while (infile)
	{
		if (infile->type == REDIR_IN)
		{
			fd = open(infile->file, O_RDONLY);
			if (fd == -1)
			{
				perror(infile->file);
				return (1);
			}
			close(fd);
		}
		prev = infile;
		infile = infile->next;
	}
	*final = prev;
	return (0);
}

int	handle_infile(t_command *cmd, int dock)
{
	t_redir	*final;
	int		ret;

	if (!cmd->infile)
		return (0);
	ret = iterate_infiles(cmd, &final);
	if (ret)
		return (1);
	return (final_infile_redirect(final, dock));
}
