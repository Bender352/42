/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_token_len_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knjaloun <knjaloun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 14:54:07 by knjaloun          #+#    #+#             */
/*   Updated: 2025/05/29 16:40:13 by knjaloun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minishell.h"

int	special_case_check(char *input, int count, int saved_quotes)
{
	int	i;
	int	count_quotes;

	i = 0;
	count_quotes = 0;
	while (i < count)
	{
		if (input[i] == '\"' || input[i] == '\'')
			count_quotes++;
		if (input[i] == '\\' && input[i + 1] == '\"')
			i++;
		i++;
	}
	if (count_quotes == saved_quotes && saved_quotes > 0)
		return (1);
	return (0);
}

int	skip_whitespace(char *input)
{
	int	i;

	i = 0;
	while (input && (input[i] == ' ' || input[i] == '\t'))
		i++;
	return (i);
}

int	is_special_operation(char c)
{
	if (c == '>' || c == '<')
		return (1);
	if (c == '|')
		return (1);
	return (0);
}

int	search_quote_init(t_sq *sq, char *input)
{
	sq->i = 0;
	sq->quotes = 1;
	sq->update_del = 0;
	if (input[sq->i] == '\'' || input[sq->i] == '\"')
		sq->del = input[sq->i];
	else
		return (1);
	sq->i++;
	return (0);
}

int	to_search_quotes(char *input)
{
	t_sq	sq;

	if (search_quote_init(&sq, input))
		return (0);
	while (input && (input[sq.i] == '\'' || input[sq.i] == '\"'))
	{
		if (sq.update_del == 1)
		{
			sq.quotes++;
			sq.update_del = 0;
			sq.del = input[sq.i];
			sq.i++;
			continue ;
		}
		if (input[sq.i] == sq.del)
		{
			sq.quotes--;
			sq.update_del = 1;
		}
		sq.i++;
	}
	return (sq.quotes);
}
