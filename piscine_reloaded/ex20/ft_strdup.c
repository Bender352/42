/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbruck <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 19:33:22 by sbruck            #+#    #+#             */
/*   Updated: 2024/10/18 19:33:24 by sbruck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strdup(char *src);
int	sizeofstr(char *str);

char	*ft_strdup(char *src)
{
	char	*copy;
	int	i;
		
	copy = (char*)malloc(sizeof(char) * (sizeofstr(src) + 1));
	
	if (copy == NULL)
		return (0);
	i = 0;
	while (src[i])
	{
		copy[i] = src[i];
		i++;
	}
	return copy;
}

int	sizeofstr(char *str)
{
	int	i;
	
	i = 0;

	while (str[i])
		i++;
	return (i);
}
