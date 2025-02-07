/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbruck <sbruck@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 13:53:30 by sbruck            #+#    #+#             */
/*   Updated: 2025/02/07 22:22:21 by sbruck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    sort3(t_stack   **head)
{
    int     i;

    i = find_highest(head);
    if (0 == i)
    {
        r(head);
        print_move("ra");
    }
    else if (1 == i)
    {
        s(head);
        r(head);
        print_move("sa");
        print_move("ra");
    }
    i = find_smallest(head);
    if (1 == i)
    {
        s(head);
        print_move("sa");
    }
}
