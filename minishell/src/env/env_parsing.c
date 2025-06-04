/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevinnjaloung <kevinnjaloung@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 15:45:15 by knjaloun          #+#    #+#             */
/*   Updated: 2025/05/28 22:02:25 by kevinnjalou      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minishell.h"

int	get_value_len(char *str_env, int start)
{
	int	i;

	i = start;
	if (str_env[i] == '=')
		i++;
	while (str_env[i])
	{
		i++;
	}
	return (i);
}

int	get_name_len(char *str_env)
{
	int	i;

	i = 0;
	while (str_env[i] != '=')
	{
		i++;
	}
	return (i);
}

int	get_env_index(int reset)
{
	static int	i = -1;

	if (reset == 1)
		i = -1;
	i++;
	return (i);
}

void	set_env_data(t_henv *henv, char **env_list)
{
	int	i;

	i = get_env_index(0);
	henv->name_len = get_name_len(env_list[i]);
	henv->value_len = get_value_len(env_list[i], (henv->name_len));
	henv->name = malloc(sizeof(char) * ((henv->name_len) + 1));
	if ((henv->value_len) == 0)
	{
		(henv->value) = malloc(sizeof(char) * 2);
		ft_strlcpy(henv->value, "\n", 2);
	}
	else
	{
		henv->value = malloc(sizeof(char) * ((henv->value_len) + 1));
		ft_strlcpy((henv->value), env_list[i] + (henv->name_len) + 1,
			(henv->value_len) + 1);
	}
	ft_strlcpy((henv->name), env_list[i], (henv->name_len) + 1);
	i++;
}

void	env_init(t_env **env, char **env_list)
{
	t_henv	henv;

	henv.i = 1;
	set_env_data(&henv, env_list);
	fst_env_node(env, henv.name, henv.value, 0);
	free(henv.name);
	free(henv.value);
	while (env_list[henv.i])
	{
		set_env_data(&henv, env_list);
		add_env_end((*env), henv.name, henv.value, 0);
		free(henv.name);
		free(henv.value);
		henv.i++;
	}
}
