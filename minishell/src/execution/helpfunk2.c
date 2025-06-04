/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpfunk2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevinnjaloung <kevinnjaloung@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 11:51:56 by kevinnjalou       #+#    #+#             */
/*   Updated: 2025/05/28 21:58:23 by kevinnjalou      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minishell.h"

void	check_closefd(t_command *cmd, int *fd, int *prev_fd)
{
	if (cmd->next)
	{
		prev_fd[0] = fd[0];
		prev_fd[1] = fd[1];
	}
	else
	{
		prev_fd[0] = -1;
		prev_fd[1] = -1;
	}
	fd[0] = -1;
	fd[1] = -1;
}
