/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knjaloun <knjaloun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 10:11:15 by kevin-njalo       #+#    #+#             */
/*   Updated: 2025/05/29 19:39:07 by knjaloun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minishell.h"

int	is_redir_inquote(char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	if (str[i] && str[i] == '\"')
		return (D_QUOTE);
	if (str[i] && str[i] == '\'')
		return (S_QUOTE);
	return (NO_QUOTE);
}

int	tokenizer_helpfunk(t_error **error, char *input, t_quote_state state)
{
	if (quote_closed(*error, input, state, 0) == 1)
	{
		printf("unclosed quote detected get good!!!\n");
		return (1);
	}
	if ((*error)->error != 0)
		return (1);
	return (0);
}

void	tokenizer(t_token **token, char *input, t_error **error, t_env *env)
{
	int				i;
	int				len;
	char			*str;
	int				quote_type;
	t_quote_state	state;

	state = (t_quote_state){0};
	if (tokenizer_helpfunk(error, input, state) == 1)
		return ;
	i = 0;
	len = 0;
	while (input[i])
	{
		i += skip_whitespace(input + i);
		len = get_next_token_len(input + i, 0);
		if (len == 0)
			break ;
		str = get_token_str(len, input, i);
		quote_type = is_redir_inquote(str);
		start_token_list(token, str, error, quote_type);
		token_manage_str(*token, env, 0, 0);
		i += len;
		if ((*error)->error != 0)
			return ;
	}
}

void	check_empty_token(t_token **token, t_error **error)
{
	t_token	*temp;
	t_token	*last;
	t_token	*curr;

	last = NULL;
	curr = *token;
	if ((*error)->error != 0)
		return ;
	while (curr)
	{
		temp = curr->next;
		if (curr->str[0] == '\0')
		{
			free_empty_token(curr);
			if (last)
				last->next = temp;
			else
				*token = temp;
			if (temp)
				temp->prv = last;
		}
		else
			last = curr;
		curr = temp;
	}
}
