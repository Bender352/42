#include "get_next_line.h"
/*
int main (void)
{
    char    *buf;
    int fd = open("text.txt", O_RDONLY);
    while (buf = get_next_line(fd))
        printf("%s", buf);
    free(buf);
}
*/


int main (void)
{
    char    *c;
    char    *d;
    char    *j;

    //c = malloc (25);
    d = malloc (25);
    j = NULL;

/*
    for (size_t i = 0; i < 5; i++)
    {
        c[i] = 'a';
    }

    */
    for (size_t i = 0; i < 5; i++)
    {
        d[i] = 'b';
    }
    printf ("%s\n", c);
    printf ("%s\n", c);
    j = add_to_rest(c, d);
    printf ("%s\n", j);
    free (d);
}