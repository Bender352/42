/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbruck <sbruck@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 13:48:17 by sbruck            #+#    #+#             */
/*   Updated: 2025/02/06 19:45:44 by sbruck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int fill_stack(t_mothership *mother)
{
    t_stack *temp;
    int i;
	long int l;

    i = 0;
    while (i < element_count(mother->temp))
    {
		l = ft_atol(str[i]);
		if (l < INT_MIN || l > INT_MAX)
			show_error("A number is out of range of INT!", stack_a, stack_b);
        temp = new_node(l);
		temp->index = i;
		ft_lstadd_back(stack_a, temp);
		i++;
    }
	return (i);
}

int element_count (char **str)
{
    int i;

    i = 0;
	if (!str)
		return (0);
    while (str[i])
        i++;
    return (i);
}

int	ft_atol(const char *str)
{
	int	i;
	int	s;
	long int	res;

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

void	ft_lstadd_back(t_stack **lst, t_stack *new)
{
	t_stack	*last;

	if (!new || !lst)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	last = ft_lstlast(*lst);
	last->next = new;
	new->prev = last;
}

t_stack	*ft_lstlast(t_stack *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}