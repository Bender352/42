/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbruck <sbruck@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 18:39:43 by sbruck            #+#    #+#             */
/*   Updated: 2025/01/21 18:40:20 by sbruck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

static void    create_pixel(int x, int y, t_img *img, int color)
{
    int offset;

    offset = (y * img->line_len) + (x * (img->bpp / BITS_PER_PIXEL));
    *(unsigned int *)(img->pixels_ptr + offset) = color;
}
static void    handle_pixel(int x, int y, t_fractal *f)
{
    if (!ft_strncmp(f->name, "mandelbrot", 10))
        handle_pixel_mandel(x, y, f);
    else
        handle_pixel_julia(x, y, f);

}

void    render_frac(t_fractal *f)
{
    int x;
    int y;

    y = 0;
    while (y < HIGHT)
    {
        x = 0;
        while (x < WIDTH)
        {
            handle_pixel(x, y, f);
            x++;
        }
        y++;
    }
    mlx_put_image_to_window(f->conection, f->window, f->img.img_ptr, 0, 0);
}

/*
void    render_frac(t_fractal *f)
{
    f->start_x = fmax(0, (f->shift_x - 2.0 * f->zoom) * WIDTH / f->zoom);
    f->end_x = fmin(WIDTH, (f->shift_x + 2.0 * f->zoom) * WIDTH / f->zoom);
    f->start_y = fmax(0, (f->shift_y - 2.0 * f->zoom) * HIGHT / f->zoom);
    f->end_y = fmin(HIGHT, (f->shift_y + 2.0 * f->zoom) * HIGHT / f->zoom);
    f->x = f->start_x;
    f->y = f->start_y;
    while (f->y < f->end_y)
    {
        f->x = f->start_x;
        while (f->x < f->end_x)
        {
            handle_pixel(f->x, f->y, f);
            f->x++;
        }
        f->y++;
    }
    mlx_put_image_to_window(f->conection, f->window, f->img.img_ptr, 0, 0);
}
*/
/*
void render_frac(t_fractal *f) {
    int x, y;
    int start_x = (f->shift_x - 2.0 * f->zoom) * WIDTH / f->zoom;
    int end_x = (f->shift_x + 2.0 * f->zoom) * WIDTH / f->zoom;
    int start_y = (f->shift_y - 2.0 * f->zoom) * HIGHT / f->zoom;
    int end_y = (f->shift_y + 2.0 * f->zoom) * HIGHT / f->zoom;

    for (y = start_y; y < end_y; y++) {
        for (x = start_x; x < end_x; x++) {
            if (x >= 0 && x < WIDTH && y >= 0 && y < HIGHT) {
                handle_pixel(x, y, f);
            }
        }
    }
    mlx_put_image_to_window(f->conection, f->window, f->img.img_ptr, 0, 0);
}
*/
void    handle_pixel_mandel(int x, int y, t_fractal *f)
{
    t_complex   z;
    t_complex   c;
    int         i;
    int         color;

    z.x = 0;
    z.y = 0;
    c.x = (map (x, -2, 2, HIGHT) * f->zoom) + f->shift_x;
    c.y = (map (y, 2, -2, WIDTH) * f->zoom) + f->shift_y;
    i = -1;
    while(++i < f->max_iteration)
    {
        z = sum_complex(square_complex(z), c);
        if (((z.x * z.x) + (z.y * z.y)) > f->escape_value )
        {
            color = map(i, NEON_GREEN, HOT_PINK, f->max_iteration);
            create_pixel(x, y, &f->img, color);
            return ;
        }
    }
    create_pixel(x, y, &f->img, BLUE);
}

void    handle_pixel_julia(int x, int y, t_fractal *f)
{
    t_complex   z;
    t_complex   c;
    int         i;
    int         color;

    z.x = (map (x, -2, 2, HIGHT) * f->zoom) + f->shift_x;
    z.y = (map (y, 2, -2, WIDTH) * f->zoom) + f->shift_y;
    c.x = f->julia_x;
    c.y = f->julia_y;
    i = -1;
    while(++i < f->max_iteration)
    {
        z = sum_complex(square_complex(z), c);
        if (((z.x * z.x) + (z.y * z.y)) > f->escape_value )
        {
            color = map(i, BLACK, WHITE, f->max_iteration);
            create_pixel(x, y, &f->img, color);
            return ;
        }
        i++;
    }
    create_pixel(x, y, &f->img, ULTRAVIOLET);
}
