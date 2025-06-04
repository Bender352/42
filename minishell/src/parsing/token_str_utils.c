/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_str_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knjaloun <knjaloun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 19:09:12 by kevinnjalou       #+#    #+#             */
/*   Updated: 2025/05/29 19:05:45 by knjaloun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minishell.h"

static void	start_initt(t_rquote *rquote)
{
	rquote->i = 0;
	rquote->new_str = ft_strdup("");
	rquote->append_not_quote = malloc(sizeof(char) * 2);
	(rquote->append_not_quote)[1] = '\0';
}

static void	join_str(t_rquote *rquote, char c)
{
	char	buffer[2];

	buffer[0] = c;
	buffer[1] = '\0';
	rquote->temp = rquote->new_str;
	rquote->new_str = ft_strjoin(rquote->new_str, buffer);
	free(rquote->temp);
	(rquote->i) += 1;
}

void	replace_with_quote(char **str, char delimiter)
{
	t_rquote	rquote;

	if (delimiter == '\'')
		return ;
	start_initt(&rquote);
	while ((*str)[rquote.i])
	{
		if ((*str)[rquote.i] == '\\' && (*str)[rquote.i + 1] == '\"')
			join_str(&rquote, '\"');
		else if ((*str)[rquote.i] == '\\' && (*str)[rquote.i + 1] == '\\')
			join_str(&rquote, '\\');
		else if ((delimiter == ' ') && ((*str)[rquote.i] == '\\'
			&& (*str)[rquote.i + 1] == '\''))
			join_str(&rquote, '\'');
		else
		{
			replace_quote_help(&rquote, str);
		}
		rquote.i++;
	}
	rquote.temp = (*str);
	(*str) = rquote.new_str;
	free(rquote.temp);
	free(rquote.append_not_quote);
}
