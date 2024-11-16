/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbruck <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 13:46:52 by sbruck            #+#    #+#             */
/*   Updated: 2024/11/01 14:31:09 by sbruck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*buff;

	buff = malloc(sizeof(t_list));
	if (buff == NULL)
		return (NULL);
	buff->content = content;
	buff->next = NULL;
	return (buff);
}
