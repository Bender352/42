/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevinnjaloung <kevinnjaloung@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 19:40:16 by kevin-njalo       #+#    #+#             */
/*   Updated: 2025/05/29 18:08:05 by knjaloun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minishell.h"

t_command	*fst_command_node(t_command *cmd)
{
	cmd = malloc(sizeof(t_command));
	cmd->args = NULL;
	cmd->exec = NULL;
	cmd->pipe = 0;
	cmd->outfile = NULL;
	cmd->infile = NULL;
	cmd->next = NULL;
	return (cmd);
}

void	add_cmd_end(t_command *cmd)
{
	while (cmd->next != NULL)
		cmd = cmd->next;
	cmd->next = malloc(sizeof(t_command));
	cmd->next->args = NULL;
	cmd->next->exec = NULL;
	cmd->next->pipe = 0;
	cmd->next->infile = NULL;
	cmd->next->outfile = NULL;
	cmd->next->next = NULL;
}

/**
 * @brief this function intialize every arguments to 0
 * @param len the amount of arguments
 * @param cmd pointer to the command list
 */
void	init_cmd_args(int len, t_command *cmd)
{
	int	i;

	i = 0;
	while (i < len + 2)
	{
		cmd->args[i] = 0;
		i++;
	}
}

t_redir	*fst_redir_list(char *value, int type)
{
	t_redir	*redir;

	redir = malloc(sizeof(t_redir));
	redir->file = value;
	redir->type = type;
	redir->heredock = NULL;
	redir->next = NULL;
	return (redir);
}

void	list_redir_end(t_redir *redir, char *value, int type)
{
	while (redir->next != NULL)
		redir = redir->next;
	redir->next = malloc(sizeof(t_redir));
	redir->next->file = value;
	redir->next->type = type;
	redir->next->next = NULL;
	redir->next->heredock = NULL;
}
