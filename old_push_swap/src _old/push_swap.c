/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbruck <sbruck@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 13:48:39 by sbruck            #+#    #+#             */
/*   Updated: 2025/02/19 15:19:14 by sbruck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
-TO DO-
In case of error, it must display "Error" followed by a ’\n’ on the standard error.
Errors include for example: some arguments aren’t integers, some arguments are
bigger than an integer and/or there are duplicates.
*/

/*
when ./push_swap 3 45 6   -> I get a output. Check if this is correct if not handle it correctyl
*/

int main(int arg, char **argv)
{
    static t_stack  *stack_a;
    static t_stack  *stack_b;
    static t_mothership m;
    int total_nodes;

    m.stack_a = &stack_a;
    m.stack_b = &stack_b;
    arg = 2;
    if (arg != 2 && argv[1][0])
        return (0);
    else
        m.temp = ft_split(argv[1], ' ');
    total_nodes = fill_stack(&m);
    /*
    printf("Unsorted input stack\n");
    print_stack(&stack_a);
    printf("--------------------\n");
    */
    sort_method(&m, total_nodes);
    /*
    printf("--------------------\n");
    printf("Sorted Stack Output\n");
    print_stack(&stack_a);
    printf("--------------------\n");
    */
    free_stack(&stack_a, &stack_b);
    free_array(m.temp);
    m.temp = NULL;
    return (0);
}

void    sort_method(t_mothership *m, int total_nodes)
{
    //printf("TOTAL NODES : %d\n", total_nodes);
    if(total_nodes <= 2)
        sort2(m->stack_a);
    else if (total_nodes <= 3)
        sort3(m->stack_a);
    else
        do_the_turk(m);
    /*
    else if (total_nodes <= 15)
    {
        printf("%s", "TEST2\n");
        bubble_sort(stack_a, stack_b);

    }
    */
}

void print_stack(t_stack **stack)
{
    t_stack *buf;

    buf = *stack;
    while (buf)
    {
        printf("%ld\n", buf->i);
        buf = buf->next;
    }
}

