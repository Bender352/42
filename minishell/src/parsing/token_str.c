/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knjaloun <knjaloun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 19:12:24 by kevinnjalou       #+#    #+#             */
/*   Updated: 2025/05/29 17:59:08 by knjaloun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minishell.h"

void	token_manage_str3(t_mstr *mstr, int *count, int *i, t_token *token)
{
	*count = 0;
	mstr->found_b_slash_quote = 0;
	*i = skip_whitespace(token->str);
	*count = 0;
	mstr->del = set_delimiter(token->str[*i]);
	mstr->prev_del = mstr->del;
	mstr->joined_str = ft_strdup("");
	if (mstr->del == '\"' || mstr->del == '\'')
		(*i)++;
}

void	escape_quote(t_token *token, t_mstr *mstr, int *i, int *count)
{
	if ((token->str[*i] == '\\' && token->str[(*i) + 1] == '\"'
			&& mstr->del != '\'') || (token->str[*i] == '\\' && token->str[(*i)
				+ 1] == '\'' && mstr->del == ' ') || (token->str[(*i)] == '\\'
			&& token->str[(*i) + 1] == '\\' && mstr->del != '\''))
	{
		(*count) += 2;
		(*i) += 2;
		mstr->found_b_slash_quote = 1;
	}
}

void	str_update(t_mstr *mstr, t_token **token)
{
	mstr->temp = (*token)->str;
	(*token)->str = mstr->joined_str;
	free(mstr->temp);
}

void	str_help(t_mstr *mstr, int *i)
{
	if (mstr->found_b_slash_quote == 0)
		(*i)++;
	mstr->found_b_slash_quote = 0;
}

void	token_manage_str(t_token *token, t_env *env, int start, int count)
{
	t_mstr	mstr;
	int		i;

	while (token->next != NULL)
		token = token->next;
	token_manage_str3(&mstr, &count, &i, token);
	start = i;
	while (token->str[i])
	{
		escape_quote(token, &mstr, &i, &count);
		if (mstr.found_b_slash_quote == 1 || token->str[i] == mstr.del
			|| schould_go_in(token->str, i, mstr.del, &count))
		{
			mstr.value_str = malloc(sizeof(char) * (count + 1));
			ft_strlcpy(mstr.value_str, token->str + start, count + 1);
			replace_with_quote(&mstr.value_str, mstr.del);
			expand_str(&mstr.value_str, mstr.del, env, token);
			count = 0;
			manage_str_2(&mstr, &i, &start, token);
		}
		else
			count++;
		str_help(&mstr, &i);
	}
	str_update(&mstr, &token);
}
