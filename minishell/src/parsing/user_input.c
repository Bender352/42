/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knjaloun <knjaloun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 13:36:01 by knjaloun          #+#    #+#             */
/*   Updated: 2025/05/29 16:38:39 by knjaloun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minishell.h"

char	*get_user_input(void)
{
	char	*user_input;

	user_input = readline("minishell-> ");
	return (user_input);
}

void	set_token_special(t_token *token)
{
	if (token->type != 0)
		return ;
	token->type = get_special_operation(token);
}

void	set_token_type_help(int *command_found, int *can_be_command,
		t_token **token, t_env *env)
{
	(*token)->type = is_command(*token, *can_be_command, env);
	if ((*token)->type == COMMAND)
		*command_found = 1;
	if ((*token)->type == PIPE)
	{
		*can_be_command = 1;
		*command_found = 0;
	}
	else
		*can_be_command = 0;
}

void	set_token_type2(t_token **token, int *count_down, int command_found)
{
	if (((*token)->type == REDIR_OUT || (*token)->type == REDIR_OUT_A
			|| (*token)->type == REDIR_IN || (*token)->type == HERE_DOCK)
		&& command_found == 0)
		*count_down = 1;
	*token = (*token)->next;
}

void	set_token_type(t_token *token, t_error **error, t_env *env)
{
	int	can_be_command;
	int	count_down;
	int	command_found;

	command_found = 0;
	set_token_type_helpfunk(&count_down, &can_be_command);
	if ((*error)->error != 0)
		return ;
	if (token != NULL)
	{
		token->type = is_command(token, 1, env);
		set_token_type2(&token, &count_down, command_found);
	}
	while (token != NULL)
	{
		if (count_down == 0)
			can_be_command = 1;
		set_token_type_help(&command_found, &can_be_command, &token, env);
		count_down--;
		set_token_type2(&token, &count_down, command_found);
	}
}
