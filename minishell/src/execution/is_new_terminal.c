/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_new_terminal.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevinnjaloung <kevinnjaloung@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 12:19:03 by kevinnjalou       #+#    #+#             */
/*   Updated: 2025/05/28 21:58:25 by kevinnjalou      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minishell.h"

void	increment_shlvl(t_env **env)
{
	int		num;
	t_env	*curr;

	curr = *env;
	while (curr && !ft_cmp(curr->name, "SHLVL"))
		curr = curr->next;
	if (!curr)
		return ;
	num = ft_atoi(curr->value);
	num++;
	free(curr->value);
	curr->value = ft_itoa(num);
}
