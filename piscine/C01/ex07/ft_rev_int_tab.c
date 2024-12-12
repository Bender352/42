/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbruck <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 11:57:07 by sbruck            #+#    #+#             */
/*   Updated: 2024/07/15 13:12:35 by sbruck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_int_tab(int *tab, int size)
{
	int	i;
	int	ri;
	int	swap;

	i = 0;
	ri = size - 1;
	while (i < (size / 2))
	{
		swap = tab[i];
		tab[i] = tab[ri];
		tab[ri] = swap;
		i++;
		ri--;
	}
}
/*
#include <unistd.h>
// Function to print an integer using recursion
void	ft_putnbr(int n)
{
    char c;

    if (n >= 10)
        ft_putnbr(n / 10);
    c = (n % 10) + '0';
    write(1, &c, 1);
}

// Function to print the elements of an array
void print_array(int *tab, int size)
{
    int i;

    i = 0;
    while (i < size)
    {
        ft_putnbr(tab[i]);
        if (i < size - 1)
            write(1, ", ", 2);
        i++;
    }
    write(1, "\n", 1);
}

// Main function to demonstrate reversing an array of any size
int main(void)
{
    // You can modify the size and elements of the array here
    int tab[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    int size = sizeof(tab) / sizeof(tab[0]);

    write(1, "Original array: ", 16);
    print_array(tab, size);

    ft_rev_int_tab(tab, size);

    write(1, "Reversed array: ", 16);
    print_array(tab, size);

    return (0);
}
*/
