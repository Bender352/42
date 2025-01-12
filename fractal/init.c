#include "fractal.h"

static void    malloc_error(void)
{
    perror("Problems with malloc");
    exit(EXIT_FAILURE);
}
void    data_init(t_fractal *fractal)
{
    fractal->escape_value = ESCAPE_VALUE;
    fractal->max_iteration = MAX_INTERATION;
    fractal->shift_x = 0;
    fractal->shift_y = 0;
    fractal->zoom = 1;
    fractal->mouse_pos_x = 0;
    fractal->mouse_pos_y = 0;
    fractal->julia_x = 0;
    fractal->julia_y = 0;
}
static void    events_init(t_fractal *fractal)
{
    mlx_hook(fractal->window, KeyPress, KeyPressMask, key_handler, fractal);
    mlx_hook(fractal->window, ButtonPress, ButtonPressMask, mouse_handler, fractal);
    mlx_hook(fractal->window, DestroyNotify, StructureNotifyMask, close_handler, fractal);
}

void fractal_init(t_fractal *fractal)
{
    fractal->conection = mlx_init();
    data_init(fractal);

    if ( NULL == fractal->conection)
        malloc_error();

    fractal->window = mlx_new_window(fractal->conection,
                                    WIDTH,
                                    HIGHT,
                                    fractal->name); 

    if( NULL == fractal->window)
    {
        mlx_destroy_display(fractal->conection);
        free (fractal->conection);
        malloc_error();
    }
    fractal->img.img_ptr = mlx_new_image(fractal->conection,
                                        WIDTH,
                                        HIGHT);

    if( NULL == fractal->img.img_ptr)
    {
        mlx_destroy_window(fractal->conection, fractal->window);
        mlx_destroy_display(fractal->conection);
        free (fractal->conection);
        malloc_error();
    }
    fractal->img.pixels_ptr = mlx_get_data_addr(fractal->img.img_ptr,
                                                &fractal->img.bpp,
                                                &fractal->img.line_len,
                                                &fractal->img.endian);
    
    events_init(fractal);
    //data_init();

    

}

