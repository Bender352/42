/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knjaloun <knjaloun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 18:43:25 by knjaloun          #+#    #+#             */
/*   Updated: 2025/03/20 16:51:34 by knjaloun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_freemem(char **s)
{
	int	index;

	index = 0;
	while (*s[index])
	{
		free(s[index]);
		index++;
	}
	free(s);
}

static int	ft_tokencount(const char *s, char c)
{
	int	count;
	int	in_token;

	count = 0;
	in_token = 0;
	while (*s)
	{
		if (*s == c)
		{
			if (in_token)
			{
				in_token = 0;
				count++;
			}
		}
		else
			in_token = 1;
		s++;
	}
	if (in_token)
		count++;
	return (count);
}

static char	**ft_allocate_tokens(int token_count)
{
	char	**result;

	result = malloc(sizeof(char *) * (token_count + 1));
	if (!result)
		return (NULL);
	result[token_count] = NULL;
	return (result);
}

static char	*ft_copy_token(const char *s, int *start, char c)
{
	int		token_len;
	char	*token;

	token_len = 0;
	while (s[*start + token_len] && s[*start + token_len] != c)
		token_len++;
	token = malloc(sizeof(char) * (token_len + 1));
	if (!token)
		return (NULL);
	ft_strlcpy(token, s + *start, token_len + 1);
	*start += token_len;
	return (token);
}

char	**ft_split(const char *s, char c)
{
	char	**result;
	int		token_count;
	int		i;
	int		start;

	i = 0;
	start = 0;
	token_count = ft_tokencount(s, c);
	result = ft_allocate_tokens(token_count);
	if (!result)
		return (NULL);
	while (i < token_count)
	{
		while (s[start] == c)
			start++;
		result[i] = ft_copy_token(s, &start, c);
		if (!result[i])
		{
			ft_freemem(result);
			return (NULL);
		}
		i++;
	}
	return (result);
}
