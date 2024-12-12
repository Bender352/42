/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kuehara <kuehara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 19:22:13 by kuehara           #+#    #+#             */
/*   Updated: 2024/07/21 10:22:40 by kuehara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "grid_utils.h"
#include "solver.h"
#include <stdlib.h>
#include <unistd.h>

int	ft_atoi(const char *str)
{
	int	result;
	int	sign;

	result = 0;
	sign = 1;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	return (result * sign);
}

int	ft_parse_views(int *views, char *view_ptr)
{
	int	i;

	i = 0;
	while (i < 16)
	{
		views[i] = ft_atoi(view_ptr);
		if (views[i] < 1 || views[i] > 4)
		{
			write(1, "Error\n", 6);
			return (0);
		}
		while (*view_ptr && *view_ptr != ' ')
			view_ptr++;
		if (*view_ptr == ' ')
			view_ptr++;
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	int	grid[4][4];
	int	views[16];

	ft_init_grid(grid);
	if (argc != 2)
	{
		write(1, "Error\n", 6);
		return (1);
	}
	if (!ft_parse_views(views, argv[1]))
		return (1);
	if (ft_solve(grid, 0, 0, views))
		ft_print_grid(grid);
	else
		write(1, "Error\n", 6);
	return (0);
}
