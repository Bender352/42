#include "fractal.h"

int main(int ac, char **av)
{
    t_mlx   mlx;

    if (2 == ac && !ft_strncmp(av[1], "mandelbrot", 10) && 4 == ac && !ft_strncmp(av[1], "julia", 5) )
    {
        mlx.mlx_con = mlx_init();
        mlx_new_window(mlx.mlx_con, WIDTH, HEIGHT, "Test Window");
    }
    else
    {
        ft_putstr_fd(ERROR_MESSAGE, STDERR_FILENO);
        exit(EXIT_FAILURE);
    }
    return (0);

}