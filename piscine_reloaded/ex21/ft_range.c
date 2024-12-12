/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbruck <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 20:04:17 by sbruck            #+#    #+#             */
/*   Updated: 2024/10/18 20:04:19 by sbruck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	*ft_range(int min,int max);

int	*ft_range(int min,int max)
{
	int	delta;
	int	*int_array;
	int	i;
		
	if (min >= max)
		return (NULL);
	delta = max - min;
	int_array = (int*)malloc(sizeof(int) * (delta));
	if (int_array == NULL)
		return (NULL);
	i = 0;
	while (i < delta)
	{
		int_array[i] = min + i;
		i++;
	}
	return (int_array);
}
