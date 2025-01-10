#ifndef FRACTAL_H
# define FRACTAL_H

    # include "lib/minilibx-linux/mlx.h"
    # include "lib/libft/libft.h"
    # include "lib/ftprintf/ft_printf.h"
    # include <stdio.h>
    # include <stdlib.h>
    # include <unistd.h>
    # include <math.h>

    # define HIGHT 400
    # define WIDTH 400

    # define ERROR_MESSAGE "Please enter\n\t\033[33m\"./fractol mandelbrot\"\033[0m or\n\t\033[33m\"./julia, <value1>, <value2>\"\033[0m\n"

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
        double  x;
        double  y;
        double  win_x;
        double  win_y;
        int     max_iteration;
        char    *name;
        t_img   img;
    }   t_fractal;

  
    void    fractal_init(t_fractal *fractal);
    void    fractal_render(t_fractal *fractal);
    //mlx_loop(fractal.conection);

#endif