/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevinnjaloung <kevinnjaloung@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 16:52:58 by sbruck            #+#    #+#             */
/*   Updated: 2025/05/28 21:58:20 by kevinnjalou      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minishell.h"

// Helper: Count env nodes
int	count_env(t_env *env)
{
	int	count;

	count = 0;
	while (env)
	{
		count++;
		env = env->next;
	}
	return (count);
}

// Helper: Build environment array from t_env list
char	**build_envp(t_env *env)
{
	int		count;
	char	**envp;
	int		i;
	char	*tmp;

	count = count_env(env);
	envp = malloc(sizeof(char *) * (count + 1));
	i = 0;
	while (env)
	{
		tmp = ft_strjoin(env->name, "=");
		envp[i] = ft_strjoin(tmp, env->value);
		free(tmp);
		i++;
		env = env->next;
	}
	envp[i] = NULL;
	return (envp);
}

void	free_envp(char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		free(envp[i]);
		i++;
	}
	free(envp);
}
