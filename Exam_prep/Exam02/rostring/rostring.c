#include <unistd.h>
#include <stdio.h>

void    write_last_word (char *start, char *stop)
{
    write (1, " ", 1);
    while (start < stop)
    {
        write(1, &(*start), 1);
        //printf("\n%p\n", start);
        start++;
    }
    //write(1, "\n\0", 2);
}

int main (int ac, char **av)
{
    char    *str;
    char    *start_word;
    char    *stop_word;
    
    if (ac != 2)
    {
        write (1, "\n", 2);
        return (0);
    }
    str = av[1];
    while (' ' == *str || '\t' == *str)
        str++;
    start_word = str;
    while (*str && ' ' != *str && '\t' != *str)
        str++;
    stop_word = str ;
    while (*str && ' ' != *str && '\t' != *str)
        str++;

    while (*str)
    {
        if (' ' == *str || '\t' == *str)
        {
            while (' ' == *str || '\t' == *str)
                str++;
            write (1, " ", 1);
        }
        else
        {
            write (1, &(*str), 1);
            str++;
        }
    }
    write_last_word(start_word, stop_word);
    //printf("\n%p\n", start_word);
    //printf("%p\n", stop_word);
    return (0);
}