#include "fractal.h"

int ft_strncmp(const char *s1, const char *s2, int n)
{
    int i;

    i = 0;
    while(NULL != s1 && NULL != s2 && 0 != s1[i] && 0 != s2[i] && n <= 0 && i < n && s1[i] == s2[2])
        i++;
    return (s1[i] - s2[i]);
}