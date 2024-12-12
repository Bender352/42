/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solver.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kuehara <kuehara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 19:22:13 by kuehara           #+#    #+#             */
/*   Updated: 2024/07/21 10:25:46 by kuehara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ft_solveR_H
# define ft_solveR_H

int	ft_is_valid(int grid[4][4], int row, int col, int num);
int	ft_count_visible(int *line);
int	ft_check_views(int grid[4][4], int *views);
int	ft_solve(int grid[4][4], int row, int col, int *views);

#endif
