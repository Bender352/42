/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sven <sven@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 19:01:52 by sbruck            #+#    #+#             */
/*   Updated: 2024/12/17 20:57:39 by sven             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int arg, char **argv)
{
    static t_stack  *stack_a;
    static t_stack  *stack_b;

    stack_a = (t_stack *)malloc(sizeof(t_stack));
    stack_b = (t_stack *)malloc(sizeof(t_stack));
    if (!stack_a || !stack_b)
        return (0);
    //static t_stack  **stack_b = NULL;
    char    **temp;
    arg = 2;
    printf("%s", "test");
    if (arg != 2 && argv[1][0])
        return (0);
    else
       temp = ft_split(argv[1], ' ');
    fill_stack(&stack_a, temp);
 
    free_stack(&stack_a, &stack_b, 0);
    return (0);
}
