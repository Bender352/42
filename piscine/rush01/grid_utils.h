/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid_utils.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kuehara <kuehara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 19:22:13 by kuehara           #+#    #+#             */
/*   Updated: 2024/07/21 10:23:42 by kuehara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRID_UTILS_H
# define GRID_UTILS_H

void	ft_print_grid(int grid[4][4]);
void	ft_init_grid(int grid[4][4]);
void	ft_fill_row(int *line, int grid[4][4], int row, int rev);
void	ft_fill_col(int *line, int grid[4][4], int col, int rev);

#endif
