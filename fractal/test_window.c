#include "fractal.h"

int main(int ac, char **av)
{
    t_fractal   fractal;

    if ((2 == ac && !ft_strncmp(av[1], "mandelbrot", 10)) || (4 == ac && !ft_strncmp(av[1], "julia", 5)))
    {
        if (!ft_strncmp(av[1], "julia", 5))
        {
            fractal.julia_x = ft_atodl(av[2]);
            fractal.julia_y = ft_atodl(av[3]);
        }
        fractal.name = av[1];
        fractal_init(&fractal);
        fractal_render(&fractal);
        mlx_loop(fractal.conection);

    //    mlx_loop(fractal.conection);
    }
    else
    {
        ft_putstr_fd(ERROR_MESSAGE, STDERR_FILENO);
        exit(EXIT_FAILURE);
    }
    return (0);

}
