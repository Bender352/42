/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_aplha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbruck <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 18:30:30 by sbruck            #+#    #+#             */
/*   Updated: 2024/07/20 12:36:59 by sbruck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_alpha(char *str)
{
	int		i;
	int		retour;
	char	c;

	i = 0;
	retour = 1;
	while (*(str + i) != '\0')
	{
		c = *(str + i);
		if (c < 65 || (c > 90 && c < 97) || c > 122)
		{
			retour = 0;
		}
		i++;
	}
	return (retour);
}
