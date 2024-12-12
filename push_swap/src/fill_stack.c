/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbruck <sbruck@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 20:37:59 by sbruck            #+#    #+#             */
/*   Updated: 2024/12/12 21:09:31 by sbruck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

t_stack **fill_stack(char    **str)
{
    t_stack **stack;
    t_stack *temp;
    int i;

    i = 0;
    stack = malloc (sizeof(t_stack) * element_count(str));
    if (!stack)
    {
        stack = NULL;
        return (NULL);
    }
    while (i < element_count(str))
    {
        temp = new_stack(atoi(str[i]));
    
    }

    stack = new_stack();
}

static int element_count (char **str)
{
    int i;

    i = 0;
    while (str[i])
        i++;
    return (i);
}

static int	ft_atoi(const char *str)
{
	int	i;
	int	s;
	int	res;

	i = 0;
	s = 1;
	res = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			s = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = (res * 10) + (str[i] - '0');
		i++;
	}
	return (res * s);
}
