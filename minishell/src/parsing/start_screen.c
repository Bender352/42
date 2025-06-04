/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_screen.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevinnjaloung <kevinnjaloung@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 14:10:56 by knjaloun          #+#    #+#             */
/*   Updated: 2025/05/29 18:01:19 by knjaloun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minishell.h"

void	free_empty_token(t_token *curr)
{
	free(curr->str);
	free(curr);
}

int	ft_strisspace(const char *s)
{
	while (*s)
	{
		if (*s != ' ' && *s != '\t')
			return (0);
		s++;
	}
	return (1);
}

void	init_structs(t_minishell **sh)
{
	(*sh)->token = NULL;
	(*sh)->cmd = NULL;
	(*sh)->env_node = NULL;
	(*sh)->error = NULL;
}

void	final_free(t_token **token, t_env *env_node, t_minishell *sh)
{
	if ((*token) != NULL)
		free_tokens(token);
	free_envs(env_node);
	free(sh);
	rl_clear_history();
}
