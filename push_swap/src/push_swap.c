/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbruck <sbruck@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 19:01:52 by sbruck            #+#    #+#             */
/*   Updated: 2024/12/12 20:59:37 by sbruck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int main(int arg, char **argv)
{
    static t_stack  **stack_a;
    static t_stack  **stack_b;
    char    **temp;

    stack_a = NULL;
    stack_b = NULL;
    if (arg != 2 || argv[1][0])
        return (0);
    else
       temp = ft_split(argv[1], ' ');
    
    return (0);
}