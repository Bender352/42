/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_quote.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knjaloun <knjaloun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 17:05:34 by kevinnjalou       #+#    #+#             */
/*   Updated: 2025/05/29 17:46:16 by knjaloun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minishell.h"

static int	handle_escaped_quotes(char *input, int *i, char del)
{
	if (del == '\"' && (input[*i] == '\\' && input[*i + 1] == '\"'))
	{
		*i += 2;
		return (1);
	}
	else if (del == ' ' && (input[*i] == '\\' && (input[*i + 1] == '\"'
				|| input[*i + 1] == '\'')))
	{
		*i += 2;
		return (1);
	}
	if (del != '\'' && (input[*i] == '\\' && input[*i + 1] == '\\'))
	{
		*i += 2;
		return (1);
	}
	return (0);
}

static void	process_quote_character(char *input, int i, t_quote_state *state)
{
	if (input[i] == state->del)
	{
		if (state->in_quote)
		{
			state->in_quote = 0;
			update_quote_counts(state);
		}
		else
		{
			state->in_quote = 1;
			update_quote_counts(state);
			state->del = input[i];
		}
	}
}

static int	check_unclosed_quotes(t_error *error, t_quote_state *state)
{
	if (state->single_quote % 2 != 0 || state->double_quote % 2 != 0)
	{
		error->error = UNCLOSED_QUOTE;
		return (1);
	}
	return (0);
}

int	quote_closed(t_error *error, char *input, t_quote_state state, int i)
{
	i = skip_whitespace_and_set_delimiter(input, &state.del);
	initialize_quote_state(&state, state.del);
	update_quote_counts(&state);
	if (state.del != ' ')
	{
		state.in_quote = 1;
		i++;
	}
	while (input[i])
	{
		if (!state.in_quote)
		{
			i += skip_whitespace(input + i);
			if (input[i] == '\0')
				break ;
			state.del = set_delimiter(input[i]);
		}
		if (handle_escaped_quotes(input, &i, state.del))
			continue ;
		if (!input[i])
			break ;
		process_quote_character(input, i, &state);
		i++;
	}
	return (check_unclosed_quotes(error, &state));
}

void	remove_last_emptytoken(t_token *token, t_error *error)
{
	t_token	*temp;

	if (error->error != 0 || token == NULL || token->next == NULL)
		return ;
	while (token->next != NULL)
		token = token->next;
	if (token->str[0] == '\0')
	{
		temp = token;
		token = token->prv;
		token->next = NULL;
		if (temp->str)
			free(temp->str);
		free(temp);
	}
}
