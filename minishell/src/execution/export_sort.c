/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevinnjaloung <kevinnjaloung@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 13:40:25 by knjaloun          #+#    #+#             */
/*   Updated: 2025/05/29 18:54:27 by knjaloun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minishell.h"

int	new_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i])
	{
		if (s2[i] == '\0')
			return (0);
		i++;
	}
	return (s1[i] - s2[i]);
}

int	get_len(char **str)
{
	int	count;

	count = 0;
	while (str[count] != NULL)
		count++;
	return (count);
}

void	ft_swap(char **str1, char **str2)
{
	char	*temp;

	temp = *str1;
	*str1 = *str2;
	*str2 = temp;
}

void	selection_sort(char **str)
{
	int	i;
	int	j;
	int	end;

	i = 0;
	end = get_len(str) - 1;
	while (i < end)
	{
		j = 0;
		while (j < (end - i))
		{
			if (new_strcmp(str[j], str[j + 1]) > 0)
				ft_swap(&str[j], &str[j + 1]);
			j++;
		}
		i++;
	}
}
