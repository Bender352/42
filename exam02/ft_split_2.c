#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>



int     str_len(char *str)
{
    int i = 0;

    while (str[i])
    {
        i++;
    }
    return (i);
}
int     count_words(char *str)
{
    char    s = ' ';
    char    t = '\t';
    char    n = '\n';
    int     flag = -1;
    char    *buf;
    int     words = 1;

    while (*str)
    {
        if (*str == s || *str == t || *str == n)
            str++;
    }
    buf = str;
    while (buf)
    {
        if (*buf == s || buf == t || buf == n)
            flag = 0;
        else if (flag == 0)
        {
            flag = -1;
            words+++;
        }
        buf++;
    }
    return (words);
}

char    **ft_split(char *str)
{
    char    s = ' ';
    char    t = '\t';
    char    n = '\n';
    int     i = str_len(str);
    int     words = 0;
    char    **str_array;

    if (!str)
        return NULL;
    words = count_words(str);


}

int     main (int ac, char **av)
{
    char    **buf;
    (void)ac;
    int i = 0;


    printf ("Input string : %s\n", av[1]);
    buf = ft_split(av[1]);
    while (buf[i])
    {
        char **temp = buf;
        printf("%s\n", buf[i]);
        i++;
        free(temp[i]);
    }
    free (buf);
}