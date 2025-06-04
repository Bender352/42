/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knjaloun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 12:42:38 by knjaloun          #+#    #+#             */
/*   Updated: 2024/10/26 12:43:46 by knjaloun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*catstr;
	int		index;
	int		index_cat;

	index = 0;
	index_cat = 0;
	catstr = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (catstr == NULL)
		return (NULL);
	while (s1[index] != '\0')
	{
		catstr[index_cat] = s1[index];
		index++;
		index_cat++;
	}
	index = 0;
	while (s2[index] != '\0')
	{
		catstr[index_cat] = s2[index];
		index++;
		index_cat++;
	}
	catstr[index_cat] = '\0';
	return (catstr);
}
