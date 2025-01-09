/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbruck <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 13:53:33 by sbruck            #+#    #+#             */
/*   Updated: 2024/10/31 13:53:35 by sbruck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *s2)
{
	size_t	start_index;
	size_t	end_index;

	if (!s1 || !s2)
		return (NULL);
	end_index = ft_strlen((char *)s1);
	start_index = 0;
	while (s1[start_index] && ft_strchr(s2, s1[start_index]))
		start_index++;
	while (end_index > start_index && ft_strchr(s2, s1[end_index - 1]))
		end_index--;
	return (ft_substr(s1, start_index, end_index - start_index));
}
/*

int		contains_c(char const *set, char c);
int		define_end(char const *str, char const *set);
int		define_start(char const *str, char const *set);
int		contains_c(char const *set, char c);

char	*ft_strtrim(char const *s1, char const *s2)
{
    int start;
    int end;
    char    *str;
    char    *set;

    str =(char *) s1;
    set = s2;
    if (!str || !set)
        return (NULL);
    start = define_start(str, set);
    end = define_end(str, set);
    if (start >= end)
        return (ft_substr(str, 0, 0));
    return (ft_substr(str, start, end - start + 1));
}

int	define_end(char *str, char *set)
{
    int len_str;

    
    len_str = ft_strlen((char *)str) - 1;
    while (len_str >= 0)
    {
        if (!contains_c(set, str[len_str]))
            return (len_str);
        len_str--;
    }
    return (0);
}

int	define_start(char *str, char *set)
{
    int i;

    
    i = 0;
    while (str[i])
    {
        if (!contains_c(set, str[i]))
            return (i);
        i++;
    }
    return (ft_strlen(str)); // Return the length if all characters are in set.
}

int	contains_c(char const *set, char c)
{
    int i;

    
    i = 0;
    while (set[i])
    {
        if (set[i] == c)
            return (1);
        i++;
    }
    return (0);
}
*/
