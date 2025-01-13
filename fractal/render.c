#include "fractal.h"

static void    my_pixel_put(int x, int y, t_img *img, int color)
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
void    fractal_render(t_fractal *f)
{
    int x;
    int y;

    y = -1;
    while (++y < HIGHT)
    {
        x = -1;
        while (++x < WIDTH)
        {
            handle_pixel(x, y, f);
        }
    }
    mlx_put_image_to_window(f->conection, f->window, f->img.img_ptr, 0, 0);
}

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
            color = map(i, BLACK, WHITE, f->max_iteration);
            my_pixel_put(x, y, &f->img, color);
            return ;
        }
    }
    my_pixel_put(x, y, &f->img, BLUE);
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
            my_pixel_put(x, y, &f->img, color);
            return ;
        }
        i++;
    }
    my_pixel_put(x, y, &f->img, BLUE);
}
