/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knjaloun <knjaloun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 14:12:51 by kevin-njalo       #+#    #+#             */
/*   Updated: 2025/05/29 19:10:12 by knjaloun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minishell.h"

void	set_token_redirection(t_token *token, t_error **error)
{
	int	is_next_redir;
	int	type;

	is_next_redir = 0;
	type = 0;
	if ((*error)->error != 0)
		return ;
	while (token)
	{
		set_redirection_helpfunk(&is_next_redir, token, type);
		if (is_next_redir && token->type != ARGUMENT)
		{
			printf("minishell: Syntaxerror at unexpected Word »%s«\n",
				token->str);
			(*error)->error = UNEXPECTED_WORD;
			return ;
		}
		if (is_redir_operator(token))
		{
			is_next_redir = 1;
			type = token->type;
		}
		token = token->next;
	}
}

int	error_2(t_token *token)
{
	if (token->type == PIPE && (token->next->type != ARGUMENT
			&& token->next->type != COMMAND && token->next->type != PIPE))
	{
		if (token->next->next != NULL)
			return (1);
	}
	return (0);
}

int	found_error(t_token *token, t_error *error)
{
	if (token->prv == NULL && token->type == PIPE)
	{
		printf("SyntaxError at unexpected Word »%s«\n", token->str);
		error->error = UNEXPECTED_WORD;
		return (1);
	}
	if (token->next != NULL)
	{
		if (error_2(token) == 1)
			return (0);
		if (get_special_operation(token) != ARGUMENT
			&& get_special_operation(token->next) != ARGUMENT)
		{
			printf("SyntaxError at unexpected Word »%s«\n", token->next->str);
			error->error = UNEXPECTED_WORD;
			return (1);
		}
	}
	return (0);
}

void	validate_input(t_token *token, t_error *error)
{
	int	type;

	type = 0;
	if (error->error != 0)
		return ;
	while (token)
	{
		if (found_error(token, error) == 1)
			return ;
		type = get_special_operation(token);
		if (type != ARGUMENT && token->next == NULL)
		{
			if (type == PIPE)
				printf("SyntaxError at unexpected Word »%s«\n", token->str);
			else
				printf("SyntaxError at unexpected Word »newline«\n");
			error->error = UNEXPECTED_WORD;
			return ;
		}
		token = token->next;
	}
}

int	get_arguemnts_count(t_token *token)
{
	int	count;

	count = 0;
	while (token)
	{
		if (token->type == PIPE)
			return (count);
		if ((token->type == ARGUMENT && token->is_redir_file == 0)
			|| token->type == COMMAND)
			count++;
		token = token->next;
	}
	return (count);
}
