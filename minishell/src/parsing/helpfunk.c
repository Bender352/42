/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpfunk.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knjaloun <knjaloun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 10:11:24 by kevin-njalo       #+#    #+#             */
/*   Updated: 2025/05/29 17:51:06 by knjaloun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minishell.h"

int	set_command_helpfunk(t_token *token, t_command *cmd, int *i, t_token *head)
{
	if (token->type == COMMAND)
		set_commmand_argv_ppath(token, cmd);
	if (token->type == ARGUMENT && token->is_redir_file == 0)
	{
		set_cmd_args(token, cmd, *i);
		(*i)++;
	}
	if (token->type == ARGUMENT && token->is_redir_file != 0)
		set_redir(token, cmd);
	if (token->type == PIPE)
	{
		cmd_check(cmd, head);
		return (1);
	}
	if (token->next == NULL)
		cmd_check(cmd, head);
	return (0);
}

void	set_redirection_helpfunk(int *is_next_redir, t_token *token, int type)
{
	if ((*is_next_redir) && token->type == ARGUMENT)
	{
		token->is_redir_file = type;
		(*is_next_redir) = 0;
	}
}

void	set_token_type_helpfunk(int *count_down, int *can_be_command)
{
	(*count_down) = -1;
	(*can_be_command) = 0;
}

void	read_env_from_name_help(char **temp, char **str, char **env_value,
		char **value)
{
	*temp = *str;
	*str = ft_strjoin(*temp, *env_value);
	if (ft_cmp(*value, "?") == 1)
		free(*env_value);
	free(*temp);
	free(*value);
}
