/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpfunk3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knjaloun <knjaloun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 17:41:36 by knjaloun          #+#    #+#             */
/*   Updated: 2025/05/29 17:53:19 by knjaloun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minishell.h"

int	skip_whitespace_and_set_delimiter(char *input, char *del)
{
	int	i;

	i = 0;
	i = skip_whitespace(input);
	*del = set_delimiter(input[i]);
	return (i);
}

void	initialize_quote_state(t_quote_state *state, char del)
{
	state->double_quote = 0;
	state->single_quote = 0;
	state->in_quote = 0;
	state->del = del;
}

void	update_quote_counts(t_quote_state *state)
{
	if (state->del == '\'')
	{
		state->single_quote++;
	}
	else if (state->del == '\"')
	{
		state->double_quote++;
	}
}
