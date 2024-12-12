/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbruck <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 18:00:34 by sbruck            #+#    #+#             */
/*   Updated: 2024/10/19 18:00:36 by sbruck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_count_if(char **tab, int (*f)(char*))
{
	int	i;
	int	nb;
	
	i = 0;
	nb = 0;
	while (tab[i][0])
	{
		if(tab[i][0] == 1)
			nb++;
		i++;
	}
	return (nb);
}