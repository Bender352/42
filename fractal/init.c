#include "fractal.h"

static void    malloc_error(void)
{
    perror("Problems with malloc");
    exit(EXIT_FAILURE);
}

void fractal_init(t_fractal *fractal)
{
    fractal->conection = mlx_init();

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
    
    //events_init();
    //data_init();

    

}