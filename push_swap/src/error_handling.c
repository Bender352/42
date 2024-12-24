/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbruck <sbruck@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 14:28:27 by sbruck            #+#    #+#             */
/*   Updated: 2024/12/24 17:39:54 by sbruck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void check_format(char **str)
{



}

//check for doubl number and give a error.
int check_double(t_stack **stack)
{
    long long int   i;
    t_stack         *temp;
    t_stack         *temp2;

    temp = *stack;
    temp2 = *stack;
    while (temp->next)
    {
        i = temp->i;
        while (temp2->prev)
        {
            
        }
    }
    return(0);
}
//check if it is a digit otherwise it gives an error.
int isnumber(int i)
{
    if(i >= 0);
}
//normalise numbers of the nodes to the max size of the nodes in the list.
int normalise_numbers()
{

}