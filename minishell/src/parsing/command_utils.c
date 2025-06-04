/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevinnjaloung <kevinnjaloung@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 15:23:57 by kevin-njalo       #+#    #+#             */
/*   Updated: 2025/05/28 21:57:49 by kevinnjalou      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minishell.h"

void	set_redir(t_token *token, t_command *cmd)
{
	char	*value;

	value = ft_strdup(token->str);
	if (token->is_redir_file == REDIR_IN || token->is_redir_file == HERE_DOCK)
	{
		if (!cmd->infile)
			cmd->infile = fst_redir_list(value, token->is_redir_file);
		else
			list_redir_end(cmd->infile, value, token->is_redir_file);
	}
	else
	{
		if (!cmd->outfile)
			cmd->outfile = fst_redir_list(value, token->is_redir_file);
		else
			list_redir_end(cmd->outfile, value, token->is_redir_file);
	}
}

void	cmd_check(t_command *cmd, t_token *token)
{
	char	*arg;
	int		found;

	arg = NULL;
	found = 0;
	if (cmd->exec)
		return ;
	while (token && token->type != PIPE && found == 0)
	{
		if (token->type == ARGUMENT && token->is_redir_file == 0)
		{
			arg = ft_strdup(token->str);
			found = 1;
		}
		token = token->next;
	}
	if (arg)
		cmd->exec = arg;
	else
		cmd->exec = ft_strdup("");
}
