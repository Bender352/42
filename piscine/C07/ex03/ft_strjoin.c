/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbruck <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 16:13:41 by sbruck            #+#    #+#             */
/*   Updated: 2024/07/28 16:13:55 by sbruck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int		lenstr(char *c);
char	*ft_strjoin(int size, char **strs, char *sep);
int		total_len(int size, char **strs, char *sep);
char	*concat_all(int size, char **strs, char *sep);
char	*add_sep(char *c, char *sep);

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*concat;

	if (size == 0)
	{
		concat = malloc(sizeof(char) * 1);
		concat[0] = 0;
		return (concat);
	}
	concat = concat_all(size, strs, sep);
	return (concat);
}

int	lenstr(char *c)
{
	int	i;

	i = 0;
	while (c[i])
	{
		i++;
	}
	return (i);
}

int	total_len(int size, char **strs, char *sep)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < size)
	{
		j += lenstr(strs[i]);
		if (i < size)
			j += lenstr(sep);
		i++;
	}
	return (j);
}

char	*concat_all(int size, char **strs, char *sep)
{
	int		i;
	int		j;
	int		total_len_size;
	char	*concat;
	char	*buff_start_ptr;

	i = 0;
	total_len_size = total_len(size, strs, sep);
	concat = malloc(sizeof(char) * total_len_size + 1);
	buff_start_ptr = concat;
	while (i < size)
	{
		j = 0;
		while (strs[i][j])
		{
			*concat = strs[i][j];
			j++;
			concat++;
		}
		i++;
		if (i < size)
			concat = add_sep(concat, sep);
	}
	*concat = '\0';
	return (buff_start_ptr);
}

char	*add_sep(char *c, char *sep)
{
	int	size_sep;
	int	j;

	size_sep = lenstr(sep);
	j = 0;
	while (j < size_sep)
	{
		*c = sep[j];
		j++;
		c++;
	}
	return (c);
}
/*
#include <stdio.h>

int	main(void)
{
	char	*strings[];
	char	separator[];
	int		size;
	char	*result;

	strings[] = {"Hello", "world", "this", "is", "a", "test"};
	separator[] = ", ";
	size = 6;
	result = ft_strjoin(size, strings, separator);
	if (result)
	{
		printf("Joined string: %s\n", result);
		free(result);
	}
	else
	{
		printf("Memory allocation failed\n");
	}
	return (0);
}
*/
