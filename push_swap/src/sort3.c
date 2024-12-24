/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbruck <sbruck@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 13:53:30 by sbruck            #+#    #+#             */
/*   Updated: 2024/12/24 13:07:39 by sbruck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    sort3(t_stack   **head)
{
    if((*head)->i == 1)
    {
        if((*head)->next->i == 2)
        {
            return; // northing to do here 1, 2 ,3
        }
    }
    else if ((*head)->i == 2)
        if_2(head);
    else
        if_3(head);
}
void    if_2(t_stack **head)
{
    if((*head)->next->i == 1) // 2 ,1 ,3
        {
           s(head);
           print_move("sa");
        }
    else                        //2, 3, 1
        {
            s(head);
            r(head);
            print_move("sa");
            print_move("ra");
        }
}
void    if_3(t_stack **head)
{if((*head)->next->i == 1)   // 3, 1, 2
        {
            r(head);
            s(head);
            print_move("ra");
            print_move("sa");
        }
        else                        //3, 2, 1
        {
            r(head);
            print_move("ra");
        }
    if((*head)->next->i == 1)   // 3, 1, 2
        {
            r(head);
            s(head);
            print_move("ra");
            print_move("sa");
        }
        else                        //3, 2, 1
        {
            r(head);
            print_move("ra");
        }
}
