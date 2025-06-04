/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_token_len_utils2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knjaloun <knjaloun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 15:41:37 by knjaloun          #+#    #+#             */
/*   Updated: 2025/05/29 16:42:49 by knjaloun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minishell.h"

void	init_1(t_tlen *tlen, char *input, int *i)
{
	tlen->found_end = 0;
	tlen->quotes = 0;
	*i = skip_whitespace(input);
	tlen->count = 0;
}

void	increment(int *i, t_tlen *tlen)
{
	(*i)++;
	tlen->count++;
	tlen->remaining_quotes++;
}

void	init_2(int *i, t_tlen *tlen, char *input)
{
	tlen->remaining_quotes = to_search_quotes(input + (*i));
	tlen->count = tlen->quotes;
	(*i) += tlen->quotes;
}
