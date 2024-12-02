/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbruck <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 18:51:44 by sbruck            #+#    #+#             */
/*   Updated: 2024/11/09 18:51:46 by sbruck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int main ()
{
    int nbr[] = {42, INT_MIN, INT_MAX, 0, -1, -256};
    char *str[] = {"Hello World!", "test", "", "c42"};
    
    printf("-----------------------------------\n");
    printf("\t\tOriginal Printf\n");
    for(int i = 0; i < 6; i++)
        printf ("Length of this is %d\n", printf(" int = %d \n", nbr[i]));
    for(int i = 0; i < 4; i++)
        printf ("Length of this is %d\n", printf(" str = %s \n", str[i]));
    printf ("Length of this is %d\n", printf ("Print char %c: -->  %c\n", 'a', 'a'));
    printf ("Length of this is %d\n", printf ("Print the address of *str: %p\n", *str));
    printf ("Length of this is %d\n", printf ("Print a unsigned int (u) %d : ---> %u\n", 42, 42));
    printf ("Length of this is %d\n", printf ("Print a unsigned int (u) %d : ---> %u\n", -850, -850));
    printf ("Length of this is %d\n", printf ("Print int %d to hex lower: %x\n", 52, 52));
    printf ("Length of this is %d\n", printf ("Print int %d to hex lower: %x\n", -104, -104));
    printf ("Length of this is %d\n", printf ("Print int %d to hex upper: %X\n", 53452, 53452));
    printf ("Length of this is %d\n", printf ("Print int %d to hex upper: %X\n", -104, -104));
    printf ("Length of this is %d\n", printf ("Print a lot of %%\n"));
    printf("\n-----------------------------------\n");
    printf("\t\tMy ft_Printf version\n");
    for(int i = 0; i < 6; i++)
        ft_printf ("Length of this is %d\n", ft_printf(" int = %d \n", nbr[i]));
    for(int i = 0; i < 4; i++)
        ft_printf ("Length of this is %d\n", ft_printf(" str = %s \n", str[i]));
    ft_printf ("Length of this is %d\n", ft_printf ("Print char %c: -->  %c\n", 'a', 'a'));
    ft_printf ("Length of this is %d\n", ft_printf ("Print the address of *str: %p\n", *str));
    ft_printf ("Length of this is %d\n", ft_printf ("Print a unsigned int (u) %d : ---> %u\n", 42, 42));
    ft_printf ("Length of this is %d\n", ft_printf ("Print a unsigned int (u) %d : ---> %u\n", -850, -850));
    ft_printf ("Length of this is %d\n", ft_printf ("Print int %d to hex lower: %x\n", 52, 52));
    ft_printf ("Length of this is %d\n", ft_printf ("Print int %d to hex lower: %x\n", -104, -104));
    ft_printf ("Length of this is %d\n", ft_printf ("Print int %d to hex upper: %X\n", 53452, 53452));
    ft_printf ("Length of this is %d\n", ft_printf ("Print int %d to hex upper: %X\n", -104, -104));
    ft_printf ("Length of this is %d\n", ft_printf ("Print a lot of %%\n"));
    printf("\n-----------------------------------\n");
}
