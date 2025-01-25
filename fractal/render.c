/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbruck <sbruck@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 17:57:55 by sbruck            #+#    #+#             */
/*   Updated: 2025/01/25 18:00:48 by sbruck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

static void	create_pixel(int x, int y, t_img *img, int color)
{
	int	offset;

	offset = (y * img->line_len) + (x * (img->bpp / 8));
	*(unsigned int *)(img->pixels_ptr + offset) = color;
}

static void	handle_pixel_mandel(t_fractal *f, int x, int y)
{
	t_complex	z;
	t_complex	c;
	int			i;
	int			color;

	z.x = 0.0;
	z.y = 0.0;
	c.x = f->r;
	c.y = f->i;
	i = 0;
	while (i < f->max_iteration)
	{
		z = add_coordinates(square_coordinates(z), c);
		if ((z.x * z.x + z.y * z.y) > f->escape_value)
		{
			color = map(i, NEON_GREEN, HOT_PINK, f->max_iteration);
			create_pixel(x, y, &f->img, color);
			return ;
		}
		i++;
	}
	create_pixel(x, y, &f->img, BLUE);
}

static void	handle_pixel_julia(t_fractal *f, int x, int y)
{
	t_complex	z;
	t_complex	c;
	int			i;
	int			color;

	z.x = f->r;
	z.y = f->i;
	c.x = f->julia_x;
	c.y = f->julia_y;
	i = 0;
	while (i < f->max_iteration)
	{
		z = add_coordinates(square_coordinates(z), c);
		if ((z.x * z.x + z.y * z.y) > f->escape_value)
		{
			color = map(i, BLACK, WHITE, f->max_iteration);
			create_pixel(x, y, &f->img, color);
			return ;
		}
		i++;
	}
	create_pixel(x, y, &f->img, ULTRAVIOLET);
}

void	render_frac(t_fractal *f)
{
	int	x;
	int	y;

	f->min_r = f->shift_x - 2.0 * f->zoom;
	f->max_r = f->shift_x + 2.0 * f->zoom;
	f->min_i = f->shift_y - 2.0 * f->zoom;
	f->max_i = f->shift_y + 2.0 * f->zoom;
	y = 0;
	while (y < HIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			f->r = f->min_r + (x / (double)(WIDTH - 1)) * (f->max_r - f->min_r);
			f->i = f->max_i - (y / (double)(HIGHT - 1)) * (f->max_i - f->min_i);
			if (!ft_strncmp(f->name, "mandelbrot", 10))
				handle_pixel_mandel(f, x, y);
			else
				handle_pixel_julia(f, x, y);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(f->conection, f->window, f->img.img_ptr, 0, 0);
}
