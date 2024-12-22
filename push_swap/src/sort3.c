/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbruck <sbruck@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 13:53:30 by sbruck            #+#    #+#             */
/*   Updated: 2024/12/22 23:24:41 by sbruck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    sort3(t_stack   **head)
{
    if((*head)->i == 1)
    {
        if((*head)->next->i == 2)
        {
            return // northing to do here 1, 2 ,3
        }
    }
    else if ((*head)->i == 2)
    {
        if((*head)->next->i == 1) // 2 ,1 ,3
        {
            //do  sa finsh
        }
        else                        //2, 3, 1
        {
            //sa, ra, finish
        }
    }
    else
    {
        if((*head)->next->i == 1)   // 3, 1, 2
        {
            //
        }
        else                        //3, 2, 1
        {
            //ra finish
        }
    }
}
