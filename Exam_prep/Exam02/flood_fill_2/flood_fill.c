#include "flood_fill.h"

void    run(char **tab, t_point *size, t_point *pos, char find)
{
    if (pos->x < 0 || pos->x > size.x || pos->y < 0 || pos->y > size.y || tab[pos.y][pos.x] != find)
        return;
    tab[pos.y][pos.x] = 'F';
    run (tab, size, (t_point){pos.x + 1, pos.y}, find);
    run (tab, size, (t_point){pos.x - 1, pos.y}, find);
    run (tab, size, (t_point){pos.x, pos.y + 1}, find);
    run (tab, size, (t_point){pos.x, pos.y - 1}, find);
}


void    flood_fill(char **tab, t_point size, t_point begin)
{
    char    find = tab[begin.y][begin.x];
    run (tab, size, begin, find);
}