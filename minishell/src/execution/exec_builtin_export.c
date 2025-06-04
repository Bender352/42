/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_builtin_export.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knjaloun <knjaloun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 19:24:19 by sbruck            #+#    #+#             */
/*   Updated: 2025/05/29 19:16:44 by knjaloun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minishell.h"

static int	has_spaces(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (' ' == str[i])
			return (1);
		i++;
	}
	return (0);
}

int	has_equal(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if ('=' == str[i])
			return (1);
		i++;
	}
	return (0);
}

static char	*get_value(char *str)
{
	char	*return_str;

	while (*str && *str != '=')
		str++;
	if (*str == '=')
		return_str = ft_strdup(str + 1);
	else
		return_str = NULL;
	return (return_str);
}

int	builtin_export(t_env **env, t_command *cmd, t_echo_data *echo_data, t_fd fd)
{
	char	*data;
	char	**name;
	char	*str;
	int		i;

	i = 1;
	if (export_error(cmd, *env, echo_data, fd))
		return (1);
	if (has_spaces(cmd->args[1]) && cmd->args[2] != NULL)
		return (1);
	while (cmd->args && cmd->args[i] && !echo_data->head->next)
	{
		if (invalid_export_value(cmd, &i, env) == 1)
			continue ;
		str = cmd->args[i];
		data = get_value(str);
		name = ft_split(cmd->args[i], '=');
		if (env_exits(*env, name[0]))
			env_overwrite(*env, name[0], data);
		else
			add_env_end(*env, name[0], data, 0);
		free_export(name, &data);
		i++;
	}
	return (0);
}
