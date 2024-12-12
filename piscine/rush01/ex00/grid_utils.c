/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kuehara <kuehara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 19:22:13 by kuehara           #+#    #+#             */
/*   Updated: 2024/07/21 10:22:07 by kuehara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "grid_utils.h"
#include <unistd.h>

void	ft_print_grid(int grid[4][4])
{
	char	c;
	int		i;
	int		j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			c = grid[i][j] + '0';
			write(1, &c, 1);
			if (j < 3)
				write(1, " ", 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}

void	ft_init_grid(int grid[4][4])
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			grid[i][j] = 0;
			j++;
		}
		i++;
	}
}

void	ft_fill_row(int *line, int grid[4][4], int row, int rev)
{
	if (!rev)
	{
		line[0] = grid[row][0];
		line[1] = grid[row][1];
		line[2] = grid[row][2];
		line[3] = grid[row][3];
	}
	else
	{
		line[0] = grid[row][3];
		line[1] = grid[row][2];
		line[2] = grid[row][1];
		line[3] = grid[row][0];
	}
}

void	ft_fill_col(int *line, int grid[4][4], int col, int rev)
{
	if (!rev)
	{
		line[0] = grid[0][col];
		line[1] = grid[1][col];
		line[2] = grid[2][col];
		line[3] = grid[3][col];
	}
	else
	{
		line[0] = grid[3][col];
		line[1] = grid[2][col];
		line[2] = grid[1][col];
		line[3] = grid[0][col];
	}
}
