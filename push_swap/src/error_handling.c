/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbruck <sbruck@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 14:28:27 by sbruck            #+#    #+#             */
/*   Updated: 2025/03/08 15:34:42 by sbruck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void check_format(char **str)
{
    (void) str;
}

//check for doubl number and give a error.

int check_input_error(t_mothership *m)
{
    long long int   i;
    t_stack         *temp;
    t_stack         *temp2;

    temp = *(m->stack_a);
    while (temp)
    {
        i = temp->i;
        temp2 = temp->next;  // Start checking from the next node to avoid self-comparison
        while (temp2)
        {
            if (temp2->i == i)
            {
                m->error_msg = "Error";
                show_error(m);
                return (1);  // Stop execution when a duplicate is found
            }
            temp2 = temp->next;
        }
        temp = temp->next;
    }
    return (0);
}

//check if it is a digit otherwise it gives an error.
int isnumber(int i)
{
    (void) i;
    if(i >= 0)
    {

    }
    return (0);
}
void    show_error(t_mothership *m)
{
    free_stack (m->stack_a, m->stack_b);
    free_array (m->temp);
    perror(m->error_msg);
    exit(1);
}
