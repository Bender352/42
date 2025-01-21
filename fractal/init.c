/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbruck <sbruck@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 18:39:52 by sbruck            #+#    #+#             */
/*   Updated: 2025/01/21 18:39:53 by sbruck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

static void    malloc_error(void)
{
    perror("Problems with malloc");
    exit(EXIT_FAILURE);
}
void    data_init(t_fractal *f)
{
    f->escape_value = ESCAPE_VALUE;
    f->max_iteration = MAX_INTERATION;
    f->conection = NULL;
    f->shift_x = 0;
    f->shift_y = 0;
    f->zoom = 1;
    f->mouse_pos_x = 0;
    f->mouse_pos_y = 0;
    f->x = 0;
    f->start_x = 0;
    f->end_x = 0;
    f->y = 0;
    f->start_y = 0;
    f->end_y = 0;
}
static void    events_init(t_fractal *f)
{
    mlx_hook(f->window, KeyPress, KeyPressMask, key_handler, f);
    mlx_hook(f->window, ButtonPress, ButtonPressMask, mouse_handler, f);
    mlx_hook(f->window, DestroyNotify, StructureNotifyMask, close_handler, f);
}

void fractal_init(t_fractal *f)
{
    data_init(f);
    f->conection = mlx_init();
    if ( NULL == f->conection)
        malloc_error();
    f->window = mlx_new_window(f->conection, WIDTH, HIGHT, f->name); 
    if( NULL == f->window)
    {
        mlx_destroy_display(f->conection);
        free (f->conection);
        malloc_error();
    }
    f->img.img_ptr = mlx_new_image(f->conection, WIDTH, HIGHT);
    if( NULL == f->img.img_ptr)
    {
        mlx_destroy_window(f->conection, f->window);
        mlx_destroy_display(f->conection);
        free (f->conection);
        malloc_error();
    }
    f->img.pixels_ptr = mlx_get_data_addr(f->img.img_ptr, &f->img.bpp, &f->img.line_len, &f->img.endian);
    events_init(f);
}

