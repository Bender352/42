/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knjaloun <knjaloun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 15:48:26 by knjaloun          #+#    #+#             */
/*   Updated: 2025/05/29 19:06:49 by knjaloun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minishell.h"

t_env	*fst_env_node(t_env **env, char *name, char *value, int hide)
{
	char	*temp;

	temp = value;
	if (value == NULL)
	{
		temp = malloc(2);
		ft_strlcpy(temp, "\n", 2);
	}
	(*env) = malloc(sizeof(t_env));
	(*env)->name = malloc(sizeof(char) * (ft_strlen(name) + 1));
	(*env)->value = malloc(sizeof(char) * (ft_strlen(temp) + 1));
	ft_strlcpy((*env)->name, name, ft_strlen(name) + 1);
	ft_strlcpy((*env)->value, temp, ft_strlen(temp) + 1);
	(*env)->env_hide = hide;
	(*env)->next = NULL;
	if (value == NULL)
		free(temp);
	return (*env);
}

void	add_env_end(t_env *env, char *name, char *value, int hide)
{
	char	*temp;

	temp = value;
	while (env->next != NULL)
		env = env->next;
	if (value == NULL)
	{
		temp = malloc(2);
		ft_strlcpy(temp, "\n", 2);
	}
	env->next = malloc(sizeof(t_env));
	env->next->next = NULL;
	env->next->env_hide = hide;
	env->next->name = malloc(sizeof(char) * (ft_strlen(name) + 1));
	env->next->value = malloc(sizeof(char) * (ft_strlen(temp) + 1));
	ft_strlcpy(env->next->value, temp, ft_strlen(temp) + 1);
	ft_strlcpy(env->next->name, name, ft_strlen(name) + 1);
	if (value == NULL)
		free(temp);
}

void	print_env(t_env *env)
{
	if (env && (env->name && env->value))
	{
		if (env->env_hide == 0)
		{
			printf("%s=", env->name);
			printf("%s\n", env->value);
		}
	}
	else
		return ;
	if (env->next != NULL)
		print_env(env->next);
}

void	free_envs(t_env *env)
{
	t_env	*temp;

	while (env != NULL)
	{
		temp = env->next;
		if (env->name)
			free(env->name);
		if (env->value)
			free(env->value);
		env->name = NULL;
		env->value = NULL;
		if (env)
			free(env);
		env = temp;
	}
	env = NULL;
}

char	*get_env_value(char *name, t_env *env)
{
	if (ft_cmp(name, "?"))
		return (ft_itoa(g_exit_signal));
	while (env)
	{
		if (ft_cmp(name, env->name))
			return (env->value);
		env = env->next;
	}
	return (NULL);
}
