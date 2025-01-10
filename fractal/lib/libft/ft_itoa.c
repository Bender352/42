/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbruck <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 13:45:21 by sbruck            #+#    #+#             */
/*   Updated: 2024/10/31 13:45:23 by sbruck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_size(int n)
{
	size_t	size;

	if (n > 0)
		size = 0;
	else
		size = 1;
	while (n)
	{
		n /= 10;
		size++;
	}
	return (size);
}

char	*ft_itoa(int n)
{
	char	*result;
	long	num;
	size_t	size;

	num = (long) n;
	size = get_size(n);
	if (n < 0)
		num *= -1;
	result = (char *) malloc(size + 1);
	if (!result)
		return (NULL);
	*(result + size--) = '\0';
	while (num > 0)
	{
		*(result + size--) = (num % 10) + '0';
		num /= 10;
	}
	if (size == 0 && result[1] == '\0')
		*(result + size) = '0';
	else if (size == 0 && result[1])
		*(result + size) = '-';
	return (result);
}
/*
int	main(void)
{
	int		test_cases[];
	int		num_cases;
	char	*result;

    // Test cases
    test_cases[] = {42, -42, 0, 123456, -123456, INT_MIN, INT_MAX};
    num_cases = sizeof(test_cases) / sizeof(test_cases[0]);
    
    // Loop through test cases
    for (int i = 0; i < num_cases; i++)
    {
        result = ft_itoa(test_cases[i]);
        if (result)
        {
            printf("ft_itoa(%d) = %s\n", test_cases[i], result);
            //free(result); // Free the allocated memory
        }
        else
        {
            printf("Memory allocation failed for %d\n", test_cases[i]);
        }
    }
    return (0);
}
*/
