/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpfunk2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knjaloun <knjaloun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 17:31:50 by knjaloun          #+#    #+#             */
/*   Updated: 2025/05/29 17:54:48 by knjaloun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minishell.h"

void	expand_init(int *i, char **new_str, char **append)
{
	*i = 0;
	*new_str = ft_strdup("");
	*append = malloc(sizeof(char) * 2);
	(*append)[1] = '\0';
}

int	prev_isdock(t_token *token)
{
	if (token == NULL)
		return (0);
	if (ft_cmp("<<", token->str) == 1)
		return (1);
	return (0);
}

int	is_redir_operator(t_token *token)
{
	if (token->type == REDIR_IN || token->type == REDIR_OUT
		|| token->type == REDIR_OUT_A || token->type == HERE_DOCK)
		return (1);
	return (0);
}
