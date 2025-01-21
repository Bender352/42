#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void    put_str(char *str)
{
    int i = 0;

    while (str[i])
    {
        write (1, str, 1);
        i++;
    }
}

int str_len (char *str)
{
    int i = 0;
    while (str[i])
        i++;
    return(i);
}


void    add_new_str (char *buf, char *str, int begin, int end)
{
    int i = str_len(buf);
    if (0  != i)
    {
        buf[i++] = ' ';
        while (begin <= end)
        {
            buf[i++] = str[begin++]; 
            //printf("..");
        }
    }
    buf[++i] = 0;
}

int main(int ac, char **av)
{
    int     i = 0;
    int     t = 0;
    int     len;
    int     last = 0;
    int     first = 0;
    int     buf_pos = 0;
    char    *str;
    char    *new_str;

    printf("..");
    if (ac != 2 && av[1] == NULL)
    {
        write (1, "\n", 1);
        return (0);
    }
    str = av[1];
    len = str_len(str);
    new_str = malloc(len + 5);
    new_str[len] = 0;
    len--;
    last = len;
    printf("..");
    while (len >= 0)
    {
        if(str[len] == '\t' || str[len] == ' ')
        {
            first = len + 1;
            add_new_str(new_str, str, first, last);
            //printf("..");
        }
        i--;
    }
    put_str(new_str);
    free(new_str);
    return(0);
}

