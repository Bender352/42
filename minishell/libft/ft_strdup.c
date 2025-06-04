/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knjaloun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 15:36:22 by knjaloun          #+#    #+#             */
/*   Updated: 2024/10/24 17:33:07 by knjaloun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*text;
	size_t	index;

	index = 0;
	text = malloc((sizeof(char) * ft_strlen(s)) + 1);
	if (!text)
	{
		return (NULL);
	}
	while (s[index] != '\0')
	{
		text[index] = s[index];
		index++;
	}
	text[index] = '\0';
	return (text);
}
