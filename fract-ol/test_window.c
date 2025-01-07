#include "fractal.h"

int main(void)
{
    t_mlx   mlx;

    mlx.mlx_con = mlx_init();
    mlx_new_window(mlx.mlx_con, WIDTH, HEIGHT, "Test Window");
    return (0);


}