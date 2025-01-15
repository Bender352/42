#include "flood_fill.h"

void    fill(char **tab, t_point size, t_point c, char t)
{
    if (c.x < 0 || c.x >= size.x || c.y < 0 || c.y >= size.y || tab[c.y][c.x] != t)
        return;
    tab[c.y][c.x] = 'F';
    fill(tab, size, (t_point){c.x + 1, c.y}, t);
    fill(tab, size, (t_point){c.x - 1, c.y}, t);
    fill(tab, size, (t_point){c.x, c.y + 1}, t);
    fill(tab, size, (t_point){c.x, c.y - 1}, t);
}

void  flood_fill(char **tab, t_point size, t_point begin)
{
    char    c;

    c = tab[begin.y][begin.x];
    fill (tab, size, begin, c);
}
