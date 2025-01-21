/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbruck <sbruck@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 18:39:47 by sbruck            #+#    #+#             */
/*   Updated: 2025/01/21 18:39:47 by sbruck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTAL_H
# define FRACTAL_H

    # include "lib/minilibx-linux/mlx.h"
    # include "lib/libft/libft.h"
    # include "lib/ftprintf/ft_printf.h"
    # include <stdio.h>
    # include <stdlib.h>
    # include <unistd.h>
    # include <math.h>
    # include <X11/X.h>
    # include <X11/keysym.h>

    # define HIGHT 1200
    # define WIDTH 1200
    # define ESCAPE_VALUE 4;
    # define MAX_INTERATION 42;

    # define ERROR_MESSAGE "Please enter\n\t\033[1;35;5;47m\"./fractol mandelbrot\"\033[0m or\n\t\033[1;35;5;47m\"./julia, <value1>, <value2>\"\033[0m\n"

    # define BLACK    0x000000
    # define WHITE    0xFFFFFF
    # define RED      0xFF0000
    # define GREEN    0x00FF00
    # define BLUE     0x0000FF
    # define YELLOW   0xFFFF00
    # define MAGENTA  0xFF00FF
    # define CYAN     0x00FFFF

    # define ELECTRIC_PINK  0xFF00FF
    # define NEON_GREEN     0x00FF7F
    # define HOT_PINK       0xFF69B4
    # define ULTRAVIOLET    0x6A0DAD
    # define LIME           0x00FF00
    # define TURQUOISE      0x40E0D0
    # define FUCHSIA        0xFF00FF
    # define TANGERINE      0xFF4500
    # define VIOLET         0x8A2BE2
    # define ELECTRIC_BLUE  0x7DF9FF
    
    # define BITS_PER_PIXEL 8

    typedef struct s_img
    {
        void    *img_ptr;
        char    *pixels_ptr;
        int     bpp;
        int     endian;
        int     line_len;
    }   t_img;

    typedef struct s_fractal
    {
        void    *conection;
        void    *window;
        void    *image;
        int     x;
        int     y;
        int     start_y;
        int     end_y;
        int     start_x;
        int     end_x;
        double  shift_x;
        double  shift_y;
        double  zoom;
        double  mouse_pos_x;
        double  mouse_pos_y;
        double  julia_x;
        double  julia_y;
        int     max_iteration;
        char    *name;
        double  escape_value;
        t_img   img;
    }   t_fractal;

    typedef struct s_complex
    {
        double  x;
        double  y;
    }   t_complex;
    
    int    key_handler (int keysym, t_fractal *fractal);
  
    void    fractal_init(t_fractal *fractal);
    void    render_frac(t_fractal *fractal);
    int     close_handler (t_fractal *fractal);
    int mouse_handler(int button, int x, int y, t_fractal *fractal);
    void    handle_pixel_mandel(int x, int y, t_fractal *f);
    void    handle_pixel_julia(int x, int y, t_fractal *f);

    double  map (double nbr, double new_min, double new_max, double old_max);
    t_complex   sum_complex( t_complex z1, t_complex z2);
    t_complex   square_complex (t_complex z);


#endif