/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbruck <sbruck@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 20:37:59 by sbruck            #+#    #+#             */
/*   Updated: 2024/12/15 17:37:59 by sbruck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void fill_stack(t_stack **header, char **str)
{
    t_stack **stack;
    t_stack *temp;
    int i;

    i = 0;
	stack = NULL;
    while (i < element_count(str))
    {
        temp = new_stack(atoi(str[i]));
		ft_lstadd_back(stack, temp);
		i++;
    }
    free_stack(0, 0, temp);
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

int	ft_atoi(const char *str)
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
}
t_stack	*ft_lstlast(t_stack *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void    free_stack(t_stack  **stack_a, t_stack **stack_b, t_stack *stack)
{
	if(stack_a && *stack_a)
	{
		*stack_a = NULL;
		free(stack_a);
	}
	if(stack_b && *stack_b)
	{
		*stack_b = NULL;
		free(stack_b);	
	}
	if(stack)
	{
		free(stack);
	}

}
