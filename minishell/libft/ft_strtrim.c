/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knjaloun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 12:58:28 by knjaloun          #+#    #+#             */
/*   Updated: 2024/10/29 16:55:23 by knjaloun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_istorm(const char s, const char *set)
{
	int	index;

	index = 0;
	while (set[index] != '\0')
	{
		if (s == set[index])
		{
			return (1);
		}
		index++;
	}
	return (0);
}

static int	ft_get_startindex(const char *s1, const char *set)
{
	int	index;

	index = 0;
	while (ft_istorm(s1[index], set) == 1)
	{
		index++;
	}
	return (index);
}

static int	ft_get_stopindex(const char *s1, const char *set)
{
	int	index;

	index = ft_strlen(s1) - 1;
	while (ft_istorm(s1[index], set) == 1)
	{
		index--;
	}
	return (index);
}

static int	ft_is_justtorm(const char *s, const char *set)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (ft_istorm(s[i], set) == 0)
			return (0);
		i++;
	}
	return (1);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	size_t	startindex;
	size_t	end;
	char	*strtrimed;
	size_t	i;

	i = 0;
	startindex = ft_get_startindex(s1, set);
	end = ft_get_stopindex(s1, set);
	if (ft_is_justtorm(s1, set) == 1)
	{
		strtrimed = malloc(1);
		strtrimed[0] = '\0';
		return (strtrimed);
	}
	strtrimed = malloc(sizeof (char) * (end - startindex + 2));
	if (strtrimed == NULL)
		return (NULL);
	while (startindex <= end)
	{
		strtrimed[i] = s1[startindex];
		i++;
		startindex++;
	}
	strtrimed[i] = '\0';
	return (strtrimed);
}
/*
int main()
{
	int i = 0;
	char *h = ft_strtrim("   xxx   xxx", " x");

	while (i <= ft_strlen(h))
	{
		printf("%c ", h[i]);
		i++;
	}
}

size_t	ft_strlen(const char *s)
{
	int	index;
	int	count;

	index = 0;
	count = 0;
	while (s[index] != '\0')
	{
		count++;
		index++;
	}
	return (count);
}
*/
