/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_str_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knjaloun <knjaloun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 15:59:29 by knjaloun          #+#    #+#             */
/*   Updated: 2025/05/29 16:42:03 by knjaloun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minishell.h"

char	*get_token_str(int len, char *input, int start)
{
	char	*str;

	str = malloc(sizeof(char) * (len + 1));
	ft_strlcpy(str, input + start, len + 1);
	return (str);
}

char	set_delimiter(char c)
{
	if (c == '\"' || c == '\'')
		return (c);
	else
		return (' ');
}

int	schould_go_in(char *str, int i, char del, int *count)
{
	if (del == ' ' && str[i + 1] == '\0')
	{
		(*count) += 1;
		return (1);
	}
	if (del == ' ' && (str[i + 1] == '\"' || str[i + 1] == '\''))
	{
		(*count) += 1;
		return (1);
	}
	return (0);
}

void	manage_str_2(t_mstr *mstr, int *i, int *start, t_token *token)
{
	mstr->temp = mstr->joined_str;
	mstr->joined_str = ft_strjoin(mstr->joined_str, mstr->value_str);
	free(mstr->temp);
	free(mstr->value_str);
	if (mstr->found_b_slash_quote == 0)
		mstr->del = set_delimiter(token->str[(*i) + 1]);
	else if (mstr->found_b_slash_quote == 1 && mstr->del == ' ')
		mstr->del = set_delimiter(token->str[*i]);
	if (mstr->found_b_slash_quote == 0 && (mstr->del == '\"'
			|| mstr->del == '\''))
		(*i)++;
	if (mstr->found_b_slash_quote == 1 && (mstr->del == '\"'
			|| mstr->del == ' '))
		*start = *i;
	else
		*start = (*i) + 1;
}
