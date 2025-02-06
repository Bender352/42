/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbruck <sbruck@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 14:28:27 by sbruck            #+#    #+#             */
/*   Updated: 2025/02/06 19:32:37 by sbruck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void check_format(char **str)
{



}

//check for doubl number and give a error.
int check_input_error(t_stack **stack)
{
    long long int   i;
    t_stack         *temp;
    t_stack         *temp2;

    temp = *stack;
    temp2 = *stack;
    while (temp)
    {
        i = temp->i;
        while (temp2)
        {
            if (temp2->i == i)
                show_error("Error: Double detected!");
            temp2 = temp2->next;
        }
        temp = temp->next;
    }
    return(0);
}
//check if it is a digit otherwise it gives an error.
int isnumber(int i)
{
    if(i >= 0);
}
void    show_error(char *msg, t_stack **a, t_stack **b, char *str)
{
    free_stack (a, b);
    free_array (str);
    perror(msg);
    exit(1);
}
