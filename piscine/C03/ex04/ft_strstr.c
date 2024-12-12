/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbruck <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 18:42:10 by sbruck            #+#    #+#             */
/*   Updated: 2024/07/25 17:07:06 by sbruck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

{
	char	*start;
	char	*pattern;

	if (!*to_find)
	{
		return (str);
	}
	while (*str)
	{
		start = str;
		pattern = to_find;
		while (*str && *pattern && *str == *pattern)
		{
			str++;
			pattern++;
		}
		if (!*pattern)
		{
			return (start);
		}
		str = start + 1;
	}
	return (0);
}
/*
#include <stdio.h>
int	ft_length_char(char *c);

int	main(void)
{
	char	*str = "Hello World!";
	char	*to_find = "llo";
	char	*result = ft_strstr(str, to_find);
	printf("Look up for %s in %s source: ", to_find, str);
	printf("%s", result);
}
*/
