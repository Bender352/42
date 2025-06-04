/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knjaloun <knjaloun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 11:49:58 by knjaloun          #+#    #+#             */
/*   Updated: 2025/05/29 16:25:00 by knjaloun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minishell.h"

int	ft_cmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i])
	{
		if (s1[i] == '\0')
		{
			return (1);
		}
		i++;
	}
	return (0);
}

int	get_special_operation(t_token *token)
{
	if (token->q_type != NO_QUOTE)
		return (ARGUMENT);
	if (ft_cmp(token->str, "|"))
		return (PIPE);
	if (ft_cmp(token->str, ">"))
		return (REDIR_OUT);
	if (ft_cmp(token->str, ">>"))
		return (REDIR_OUT_A);
	if (ft_cmp(token->str, "<<"))
		return (HERE_DOCK);
	if (ft_cmp(token->str, "<"))
		return (REDIR_IN);
	return (ARGUMENT);
}

void	free_envpath(char **str)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		free(str[i]);
		i++;
	}
	if (str)
		free(str);
}

int	is_command(t_token *token, int can_be_command, t_env *env)
{
	if (can_be_command == 1)
	{
		if (is_buildin(token->str))
			return (COMMAND);
		if (ft_strchr(token->str, '/'))
		{
			if (access(token->str, X_OK) == 0)
				return (COMMAND);
			return (ARGUMENT);
		}
		if (is_non_buildin_command(token, env) == 1)
			return (COMMAND);
		return (get_special_operation(token));
	}
	else
		return (get_special_operation(token));
}
