/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredock_line_expand.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevinnjaloung <kevinnjaloung@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 21:32:58 by kevinnjalou       #+#    #+#             */
/*   Updated: 2025/05/28 21:58:24 by kevinnjalou      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minishell.h"

void	expand_dock(char **str, t_env *env)
{
	int		i;
	char	*append;
	char	*new_str;
	char	*temp;

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
