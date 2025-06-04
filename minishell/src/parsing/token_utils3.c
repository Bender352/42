/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_utils3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knjaloun <knjaloun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 16:16:05 by knjaloun          #+#    #+#             */
/*   Updated: 2025/05/29 17:28:28 by knjaloun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minishell.h"

static int	non_build_cmd_help(int *i, t_env **env, char ***env_path)
{
	*i = 0;
	while ((*env) && !ft_cmp((*env)->name, "PATH"))
		*env = (*env)->next;
	if (!(*env))
		return (1);
	*env_path = ft_split((*env)->value, ':');
	return (0);
}

static void	my_free(char ***env_path, char **final_path)
{
	free(*final_path);
	free_envpath(*env_path);
}

int	is_non_buildin_command(t_token *token, t_env *env)
{
	char	*final_path;
	char	**env_path;
	int		i;
	char	*temp;

	if (non_build_cmd_help(&i, &env, &env_path))
		return (0);
	while (env_path[i] != NULL)
	{
		final_path = ft_strjoin(env_path[i], "/");
		temp = final_path;
		final_path = ft_strjoin(final_path, token->str);
		free(temp);
		if (access(final_path, R_OK) == 0)
		{
			free(token->str);
			token->str = ft_strdup(final_path);
			my_free(&env_path, &final_path);
			return (1);
		}
		i++;
		free(final_path);
	}
	free_envpath(env_path);
	return (0);
}

void	replace_quote_help(t_rquote *rquote, char **str)
{
	rquote->temp = rquote->new_str;
	rquote->append_not_quote[0] = (*str)[rquote->i];
	rquote->new_str = ft_strjoin(rquote->new_str, rquote->append_not_quote);
	free(rquote->temp);
}
