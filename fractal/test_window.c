#include "fractal.h"

int main(int ac, char **av)
{
    t_fractal   f;

    if ((2 == ac && !ft_strncmp(av[1], "mandelbrot", 10)) || (4 == ac && !ft_strncmp(av[1], "julia", 5)))
    {
        if (!ft_strncmp(av[1], "julia", 5))
        {
            f.julia_x = ft_atodl(av[2]);
            f.julia_y = ft_atodl(av[3]);
        }
        f.name = av[1];
        fractal_init(&f);
        fractal_render(&f);
        mlx_loop(f.conection);
    }
    else
    {
        ft_putstr_fd(ERROR_MESSAGE, STDERR_FILENO);
        exit(EXIT_FAILURE);
    }
    return (0);

}
