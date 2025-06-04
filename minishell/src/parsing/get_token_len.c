/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_token_len.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knjaloun <knjaloun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 12:09:33 by kevinnjalou       #+#    #+#             */
/*   Updated: 2025/05/29 18:04:58 by knjaloun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minishell.h"

int	skip_quotes(char *input)
{
	int	i;

	i = 0;
	while (input && (input[i] == '\'' || input[i] == '\"'))
	{
		i++;
	}
	return (i);
}

void	handle_special_operation(char s1, char s2, t_tlen *tlen, int *i)
{
	if ((s1 == '>' && s2 == '>') || (s1 == '<' && s2 == '<'))
	{
		tlen->count += 2;
		(*i) += 2;
	}
	else if (s1 == '<' || s1 == '>' || s1 == '|')
	{
		tlen->count += 1;
		(*i) += 1;
	}
}

static void	len_loop(int *i, char *input, t_tlen *tlen)
{
	if (tlen->remaining_quotes > 0 && (input[(*i)] == '\''
			|| input[(*i)] == '\"'))
		tlen->remaining_quotes--;
	if (tlen->remaining_quotes == 0 && (input[(*i) + 1] == '\'' || input[(*i)
				+ 1] == '\"'))
		increment(i, tlen);
	if (tlen->remaining_quotes == 0 && (input[(*i) + 1] == ' ' || input[(*i)
				+ 1] == '\0' || is_special_operation(input[(*i) + 1])))
		tlen->found_end = 1;
	(*i)++;
	tlen->count++;
}

int	schould_return(char *input, int *i, t_tlen *tlen)
{
	if (input[*i] != '\\')
		return (0);
	while (input[*i] == '\\' && (input[(*i) + 1] == '\'' || input[(*i)
				+ 1] == '\"' || input[(*i) + 1] == '\\'))
	{
		(*i) += 2;
		tlen->count += 2;
		if (tlen->remaining_quotes == 0 && (is_special_operation(input[*i])
				|| input[(*i)] == ' ' || input[(*i)] == '\t'
				|| input[(*i)] == '\0'))
			return (1);
	}
	return (0);
}

int	get_next_token_len(char *input, int i)
{
	t_tlen	tlen;

	init_1(&tlen, input, &i);
	tlen.quotes = skip_quotes(input + i);
	init_2(&i, &tlen, input);
	if (tlen.remaining_quotes == 0 && (input[i] == ' ' || input[i] == '\0'))
		return (tlen.count);
	while (input && input[i] && (tlen.remaining_quotes > 0
			|| tlen.found_end == 0))
	{
		if (schould_return(input, &i, &tlen))
			return (tlen.count);
		if ((tlen.quotes == 0 && is_special_operation(input[i])))
		{
			handle_special_operation(input[i], input[i + 1], &tlen, &i);
			return (tlen.count);
		}
		len_loop(&i, input, &tlen);
	}
	return (tlen.count);
}
