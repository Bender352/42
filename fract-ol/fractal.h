#ifndef FRACTAL_H
# define FRACTAL_H

    # include "lib/minilibx-linux/mlx.h"
    # include "lib/libft/libft.h"
    # include "lib/ftprintf/ft_printf.h"
    # include <stdio.h>
    # include <stdlib.h>
    # include <unistd.h>
    # include <math.h>

    # define HEIGHT 400
    # define WIDTH 400

    # define ERROR_MESSAGE "Please enter\n\t\033[33m\"./fractol mandelbrot\"\033[0m or\n\t\033[33m\"./julia, <value1>, <value2>\"\033[0m\n"

    typedef struct s_mlx
    {
        void    *mlx_con;
        double  x;
        double  y;
        double  win_x;
        double  win_y;
        int     max_iteration;
        int     endian;
        int     bpp;
    }   t_mlx;

#endif