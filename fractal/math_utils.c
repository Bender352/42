#include "fractal.h"

double  map (double nbr, double new_min, double new_max, double old_max)
{
    return (new_max-new_min) * (nbr / old_max) + new_min;
}

t_complex   sum_complex (t_complex z1, t_complex z2)
{
    t_complex result;

    result.x = z1.x + z2.x;
    result.y = z1.y + z2.y;
    return (result);
}
t_complex   square_complex (t_complex z)
{
    t_complex   result;

    result.x = (z.x * z.x) - (z.y * z.y);
    result.y = 2 * z.x * z.y;
    return (result);
}