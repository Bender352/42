/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbruck <sbruck@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 18:40:35 by sbruck            #+#    #+#             */
/*   Updated: 2025/01/25 17:29:34 by sbruck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int	key_handler(int keysym, t_fractal *f)
{
	if (keysym == XK_Escape)
		close_handler(f);
	else if (keysym == XK_Page_Up)
		f->max_iteration += 1;
	else if (keysym == XK_Page_Down)
	{
		if (f->max_iteration <= 10)
			f->max_iteration = 1;
		else
			f->max_iteration -= 1;
	}
	else if (keysym == XK_Left)
		f->shift_x -= 0.1 * f->zoom;
	else if (keysym == XK_Right)
		f->shift_x += 0.1 * f->zoom;
	else if (keysym == XK_Down)
		f->shift_y -= 0.1 * f->zoom;
	else if (keysym == XK_Up)
		f->shift_y += 0.1 * f->zoom;
	render_frac(f);
	return (0);
}

int	close_handler(t_fractal *f)
{
	mlx_destroy_image(f->conection, f->img.img_ptr);
	mlx_destroy_window(f->conection, f->window);
	mlx_destroy_display(f->conection);
	free(f->conection);
	exit(EXIT_SUCCESS);
}

int	mouse_handler(int button, int x, int y, t_fractal *f)
{
	if (button == Button5)
	{
		f->zoom *= 1.05;
	}
	else if (button == Button4)
		f->zoom *= 0.95;
	(void)x;
	(void)y;
	render_frac(f);
	return (0);
}
