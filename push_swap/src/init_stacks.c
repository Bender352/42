/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbruck <sbruck@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 01:21:54 by sbruck            #+#    #+#             */
/*   Updated: 2025/03/03 18:28:40 by sbruck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    ini_stack_a(t_mothership *m)
{
    set_index(m->stack_a); //current_index
    set_index(m->stack_b);
    set_target_a(m); //set_target_a
    set_cost(m); //cost_analyse
    set_cheapest_node(m->stack_a);
}

void    ini_stack_b(t_mothership *m)
{
    set_index(m->stack_a);
    set_index(m->stack_b);
    set_target_b(m);
}