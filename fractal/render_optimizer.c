/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_optimizer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbruck <sbruck@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 18:01:53 by sbruck            #+#    #+#             */
/*   Updated: 2025/01/25 18:02:06 by sbruck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	calculate_boundaries(t_fractal *f)
{
	double	complex_range_x;
	double	complex_range_y;

	complex_range_x = 4.0 / f->zoom;
	complex_range_y = 4.0 / f->zoom;
	f->start_x = f->shift_x - (complex_range_x / 2.0);
	f->end_x = f->shift_x + (complex_range_x / 2.0);
	f->start_y = f->shift_y - (complex_range_y / 2.0);
	f->end_y = f->shift_y + (complex_range_y / 2.0);
}
