#include "fractal.h"

static void    my_pixel_put(int x, int y, t_img *img, int color)
{
    int offset;

    offset = (y * img->line_len) + (x * (img->bpp / BITS_PER_PIXEL));
    *(unsigned int *)(img->pixels_ptr + offset) = color;
}



static void    handle_pixel(int x, int y, t_fractal *fractal)
{
    t_complex   z;
    t_complex   c;
    int         i;
    int         color;

    z.x = 0;
    z.y = 0;
    c.x = (map (x, -2, 2, HIGHT) * fractal->zoom) + fractal->shift_x;
    c.y = (map (y, 2, -2, WIDTH) * fractal->zoom) + fractal->shift_y;
    i = -1;
    while(++i < fractal->max_iteration)
    {
        z = sum_complex(square_complex(z), c);

        if (((z.x * z.x) + (z.y * z.y)) > fractal->escape_value )
        {
            color = map(i, BLACK, WHITE, fractal->max_iteration);
            my_pixel_put(x, y, &fractal->img, color);
            return ;
        }
        i++;
    }
    my_pixel_put(x, y, &fractal->img, BLUE);
}
void    fractal_render(t_fractal *fractal)
{
    int x;
    int y;

    y = -1;
    while (++y < HIGHT)
    {
        x = -1;
        while (++x < WIDTH)
        {
            handle_pixel(x, y, fractal);
        }
    }
    mlx_put_image_to_window(fractal->conection, fractal->window, fractal->img.img_ptr, 0, 0);



}