/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbruck <sbruck@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 15:42:26 by sbruck            #+#    #+#             */
/*   Updated: 2025/03/08 21:33:34 by sbruck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

static void	one_string(char *argv)
{
	int	i;
	int	flag;

	flag = 0;
	i = 0;
	while (argv[i])
	{
		if (flag == 0)
		{
			if ((!(argv[i] == '+' || argv[i] == '-' || (argv[i] >= '0'
							&& argv[i] <= '9'))) || ((argv[i] == '+'
						|| argv[i] == '-') && argv[i + 1] == ' '))
				do_error();
			flag = 1;
		}
		else
		{
			if (argv[i] == ' ')
				flag = 0;
			else if (!(argv[i] >= '0' && argv[i] <= '9'))
				do_error();
		}
		i++;
	}
}

static void	multi_string(char *argv)
{
	int	i;

	i = 0;
	if (!argv[i])
		do_error();
	if (argv[0] == '+' || argv[0] == '-')
		i++;
	while (argv[i])
		if (!(argv[i] >= '0' && argv[i++] <= '9'))
			do_error();
}

void	check_input(int arg, char **argv)
{
	int	i;

	i = 1;
	if (arg < 2 && argv[1][0])
		do_error();
	else if (arg == 2)
		one_string(argv[1]);
	else
	{
		while (i < arg)
		{
			multi_string(argv[i]);
			i++;
		}
	}
}
