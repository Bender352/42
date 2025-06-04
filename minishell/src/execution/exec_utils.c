/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevinnjaloung <kevinnjaloung@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 14:07:38 by kevin-njalo       #+#    #+#             */
/*   Updated: 2025/05/28 21:58:17 by kevinnjalou      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minishell.h"

void	init_prevfd(int *fd, int *prev_fd)
{
	fd[0] = -1;
	fd[1] = -1;
	prev_fd[0] = -1;
	prev_fd[1] = -1;
}
/**
 * @brief exit the child process if an error accured
 * when trying to open a file
 * @param file the file of the error
 */

void	error_exit(char *file)
{
	perror(file);
}
