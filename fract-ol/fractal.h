#ifndef FRACTAL_H
# define FRACTAL_H

    # include "lib/minilibx-linux/mlx.h"
    # include <stdio.h>
    # include <math.h>

    # define HEIGHT 400
    # define WIDTH 400

    typedef struct s_mlx
    {
        void    *mlx_con;
        double  x;
        double  y;
        double  win_x;
        double  win_y;
        int     max_iteration;
    }   t_mlx;

#endif