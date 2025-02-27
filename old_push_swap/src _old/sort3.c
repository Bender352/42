/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbruck <sbruck@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 13:53:30 by sbruck            #+#    #+#             */
/*   Updated: 2025/02/15 22:35:19 by sbruck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    sort3(t_stack   **head)
{
    int     i;

    i = find_highest(head);
    if (0 == i)
    {
        rotate_stack(head);
        print_move("ra");
    }
    else if (1 == i)
    {
        s(head);
        rotate_stack(head);
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
