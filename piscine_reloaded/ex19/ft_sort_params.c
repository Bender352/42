/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbruck <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 17:54:31 by sbruck            #+#    #+#             */
/*   Updated: 2024/10/18 17:54:33 by sbruck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_sort_params(int arg, char **argv);
void	ft_putchar(char *str);
char	**ft_switch_array(char	**array, int pos);
void	ft_printout(char **array);

void	ft_sort_params(int arg, char **argv)
{
	int	i;
	int	m;

	i = 1;
	m = 1;
	while (i < arg)
	{
		while (m < arg - 1)
		{
			if (argv[m][0] > argv[m + 1][0])
				ft_switch_array(argv ,m);
			m++;
		}
		m = 1;
		i++;
	}
}

void	ft_putchar(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	write(1, "\n", 1);
}

char	**ft_switch_array(char	**array, int pos)
{
	char	*temp;

	temp = array[pos];
	array[pos] = array[pos + 1];
	array[pos + 1] = temp;
	return (array);
}

void	ft_printout(char **array)
{
	int	i;

	i = 1;
	while (array[i])
	{
		ft_putchar(array[i]);
		i++;
	}
}

int	main(int arg, char **argv)
{
	if (arg <= 1)
		return (0);
	else
		ft_sort_params(arg, argv);
	ft_printout (argv);
	return (0);
}
