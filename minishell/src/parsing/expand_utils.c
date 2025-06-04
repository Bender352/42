/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knjaloun <knjaloun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 11:38:05 by kevin-njalo       #+#    #+#             */
/*   Updated: 2025/05/29 18:07:46 by knjaloun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minishell.h"

static int	is_end_of_env(char c)
{
	if (c == '>' || c == '<')
		return (1);
	if (c == '|')
		return (1);
	return (0);
}

static int	get_env_name_len(char *input)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	if (input && input[i] == '?')
		return (1);
	while (input[i])
	{
		if (input[i] == '?' || input[i] == '$' || input[i] == ' '
			|| input[i] == '\'' || input[i] == '\"' || is_end_of_env(input[i]))
			return (count);
		i++;
		count++;
	}
	return (count);
}

static void	finish_name(char *temp, char *env_name, char *env_value,
		int was_empty)
{
	if (temp)
		free(temp);
	if (was_empty == 1 || ft_cmp("?", env_name))
		free(env_value);
	if (env_name)
		free(env_name);
}

int	get_env_name(char *input, char **str, t_env *env)
{
	int		name_len;
	char	*env_name;
	char	*env_value;
	char	*temp;
	int		was_empty;

	was_empty = 0;
	if (input[0] == '\0')
		return (0);
	name_len = get_env_name_len(input);
	if (name_len == 0)
		return (0);
	env_name = malloc(sizeof(char) * (name_len + 1));
	ft_strlcpy(env_name, input, name_len + 1);
	env_value = get_env_value(env_name, env);
	if (env_value == NULL)
	{
		env_value = ft_strdup("");
		was_empty = 1;
	}
	temp = (*str);
	(*str) = ft_strjoin((*str), env_value);
	finish_name(temp, env_name, env_value, was_empty);
	return (name_len);
}

void	expand_str(char **str, char del, t_env *env, t_token *token)
{
	int		i;
	char	*append;
	char	*new_str;
	char	*temp;

	if (del == '\'' || prev_isdock(token->prv))
		return ;
	expand_init(&i, &new_str, &append);
	while ((*str)[i])
	{
		if ((*str)[i] != '$')
		{
			append[0] = (*str)[i];
			temp = new_str;
			new_str = ft_strjoin(new_str, append);
			free(temp);
		}
		else
			i += get_env_name((*str) + (i + 1), &new_str, env);
		i++;
	}
	temp = (*str);
	(*str) = new_str;
	free(temp);
	free(append);
}
