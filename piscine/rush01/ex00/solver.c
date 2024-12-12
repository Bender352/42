/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kuehara <kuehara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 19:22:13 by kuehara           #+#    #+#             */
/*   Updated: 2024/07/21 10:24:55 by kuehara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solver.h"
#include "grid_utils.h"

int	ft_is_valid(int grid[4][4], int row, int col, int num)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (grid[row][i] == num || grid[i][col] == num)
			return (0);
		i++;
	}
	return (1);
}

int	ft_count_visible(int *line)
{
	int	max;
	int	count;

	max = line[0];
	count = 1;
	if (line[1] > max)
	{
		max = line[1];
		count++;
	}
	if (line[2] > max)
	{
		max = line[2];
		count++;
	}
	if (line[3] > max)
		count++;
	return (count);
}

int	ft_check_views(int grid[4][4], int *views)
{
	int	i;
	int	line[4];

	i = 0;
	while (i < 4)
	{
		ft_fill_col(line, grid, i, 0);
		if (ft_count_visible(line) != views[i])
			return (0);
		ft_fill_col(line, grid, i, 1);
		if (ft_count_visible(line) != views[i + 4])
			return (0);
		ft_fill_row(line, grid, i, 0);
		if (ft_count_visible(line) != views[i + 8])
			return (0);
		ft_fill_row(line, grid, i, 1);
		if (ft_count_visible(line) != views[i + 12])
			return (0);
		i++;
	}
	return (1);
}

int	ft_solve(int grid[4][4], int row, int col, int *views)
{
	int	num;

	num = 1;
	if (row == 4)
		return (ft_check_views(grid, views));
	if (col == 4)
		return (ft_solve(grid, row + 1, 0, views));
	while (num <= 4)
	{
		if (ft_is_valid(grid, row, col, num))
		{
			grid[row][col] = num;
			if (ft_solve(grid, row, col + 1, views))
				return (1);
			grid[row][col] = 0;
		}
		num++;
	}
	return (0);
}
