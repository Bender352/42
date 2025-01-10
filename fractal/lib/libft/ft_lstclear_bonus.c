/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbruck <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 15:08:50 by sbruck            #+#    #+#             */
/*   Updated: 2024/11/01 17:45:21 by sbruck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		temp = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = temp;
	}
	*lst = NULL;
}
/*
    temp buffers the next node address:
        temp = (*lst)->next; saves the address of 
        the node following the current head node (*lst) in temp. 
        This step is crucial because after deleting the current node,
	*lst would no longer contain a valid pointer to the next node.

    *The current node where lst points to gets deleted:
        ft_lstdelone(*lst,
		del); deletes the current node (*lst) by freeing
		 its memory and applying the del function 
		 to its content (if del is a function that 
		 handles any custom content deletion). After this step,
	the memory of the node that *lst pointed to has been freed.

    *Now lst points to an empty space in memory:
        Technically, *lst still holds the address 
        of the now-deleted node,
	but that memory is no longer allocated to the list,
	meaning it’s invalid to access. *lst must be 
	updated to move on to the next node in the list.

    lst gets the new address to the next node,
	that followed the old deleted one and becomes 
	the head node:
        *lst = temp; sets *lst to the value stored 
        in temp,
	which was the address of the next node in the 
	list. Now *lst points to this new node,
	making it the current head of the list.
        This shift prepares *lst for the next 
        iteration,
	where the next node will be processed.

    The cycle continues until it reaches the last 
    node:
        This process repeats for each node until 
        *lst becomes NULL,
	meaning there are no more nodes in the list. 
	Once the loop exits,
	*lst is explicitly set to NULL to ensure that 
	the list pointer no longer points to any nodes.

Final Result

At the end of the function,
	every node in the linked list has been 
	safely deleted,
	and *lst is set to NULL,
	indicating the list is empty and no memory 
	is left allocated.
*/
