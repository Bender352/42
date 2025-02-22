/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   the_turk_rotate_stacks.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbruck <sbruck@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 20:16:03 by sbruck            #+#    #+#             */
/*   Updated: 2025/02/22 20:18:32 by sbruck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    rr_all(t_mothership *m, t_stack *cheapy)
{
    while (*(m->stack_a) != cheapy && *(m->stack_b) != cheapy->target)
    {
        rotate_stack(m->stack_a);
        rotate_stack(m->stack_b);
        print_move("rr");
        set_index(m->stack_a);
        set_index(m->stack_b);
    }
}
void    rrr_all(t_mothership *m, t_stack *cheapy)
{
    while (*(m->stack_a) != cheapy && *(m->stack_b) != cheapy->target)
    {
        rev_rotate_stack(m->stack_a);
        rev_rotate_stack(m->stack_b);
        print_move("rrr");
        set_index(m->stack_a);
        set_index(m->stack_b);

    }
}