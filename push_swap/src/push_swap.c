/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbruck <sbruck@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 19:01:52 by sbruck            #+#    #+#             */
/*   Updated: 2024/12/15 17:37:48 by sbruck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int arg, char **argv)
{
    static t_stack  *stack_a;

    stack_a = (t_stack *)malloc(sizeof(t_stack));
    if (!stack_a)
        return (0);
    //static t_stack  **stack_b = NULL;
    char    **temp;
    arg = 2;
    printf("%s", "test");
    //stack_a = NULL;
    //stack_b = NULL;
    if (arg != 2 && argv[1][0])
        return (0);
    else
       temp = ft_split(argv[1], ' ');
    fill_stack(&stack_a, temp);
 
 /*   if (!stack_a) 
    {
        printf("Error: stack_a is NULL.\n");
        return (1);
    } */

    free_stack(&stack_a, 0, 0);
    return (0);
}
