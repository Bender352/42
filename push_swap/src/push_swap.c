/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbruck <sbruck@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 19:01:52 by sbruck            #+#    #+#             */
/*   Updated: 2024/12/12 21:51:04 by sbruck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int main(int arg, char **argv)
{
    static t_stack  **stack_a;
    static t_stack  **stack_b;
    char    **temp;
    arg = 2;
    argv[1] = malloc(20);
    argv[1] = "349 2 5 9\0";
    stack_a = NULL;
    stack_b = NULL;
    if (arg != 2 || argv[1][0])
        return (0);
    else
       temp = ft_split(argv[1], ' ');
    stack_a = fill_stack(temp);
    return (0);
}