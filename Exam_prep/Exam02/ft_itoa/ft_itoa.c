#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

int num_len (int i)
{
    int len;

    len = 0;
    if (0 == i)
        return (1);
    while (i)
    {
        i = i / 10;
        len ++;
    }
    return (len);
}

char	*ft_itoa(int nbr)
{
    int     len = num_len (nbr);
    char    *str;
    int     sign_flag = 0;

    if (nbr == INT_MIN)
        return ("-2147483648");
    if(nbr < 0)
    {
        sign_flag = 1;
        nbr = nbr * -1;
        len++;
    }    
    str = malloc(len + 1);
    if (!str)
        return (0);
    str[len] = '\0';
    len--;
    while (len >= 0)
    {
        str[len--] = (nbr % 10) + '0';
        nbr = nbr / 10;
    }
    if (sign_flag == 1)
        str[0] = '-';
    return (str);
}
int main(void)
{
    int i = 45563;
    int a = 0;
    int b = -547;
    int c = -2147483647;

    printf("1. int :\t%d\t\t|\t%s\n", i, ft_itoa(i));
    printf("1. int :\t%d\t\t|\t%s\n", a, ft_itoa(a));
    printf("1. int :\t%d\t\t|\t%s\n", b, ft_itoa(b));
    printf("1. int :\t%d\t\t|\t%s\n", c, ft_itoa(c));
    printf("1. int :\t%d\t|\t%s\n", INT_MIN, ft_itoa(INT_MIN));
    printf("1. int :\t%d\t|\t%s\n", INT_MAX, ft_itoa(INT_MAX));

}

