/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbruck <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 13:49:18 by sbruck            #+#    #+#             */
/*   Updated: 2024/10/31 13:49:20 by sbruck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	int	i;

	if (!str)
		return (NULL);
	c = (unsigned char)c;
	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return ((char *)str + i);
		i++;
	}
	if (c == '\0')
		return ((char *)str + i);
	return (NULL);
}
/*
int	main(void) {
    const char *str1 = "Hello, World!";
    const char *str2 = "Testing ft_strchr";
    const char *str3 = NULL; // Testing with NULL
    char searchChar1 = 'o';
    char searchChar2 = 'T';
    char searchChar3 = 'z'; // Character not in the string
    char searchChar4 = '\0'; // Testing the null terminator

    // Test 1: Searching for 'o' in str1
    char *result1 = ft_strchr(str1, searchChar1);
    printf("Searching for '%c' in \"%s\": %s\n", searchChar1, str1,
		result1 ? result1 : "NULL");

    // Test 2: Searching for 'T' in str2
    char *result2 = ft_strchr(str2, searchChar2);
    printf("Searching for '%c' in \"%s\": %s\n", searchChar2, str2,
		result2 ? result2 : "NULL");

    // Test 3: Searching for 'z' in str2 (not present)
    char *result3 = ft_strchr(str2, searchChar3);
    printf("Searching for '%c' in \"%s\": %s\n", searchChar3, str2,
		result3 ? result3 : "NULL");

    // Test 4: Searching for the null terminator in str1
    char *result4 = ft_strchr(str1, searchChar4);
    printf("Searching for null terminator in \"%s\": %s\n", str1,
		result4 ? result4 : "NULL");

    // Test 5: Handling NULL input
    char *result5 = ft_strchr(str3, searchChar1);
    printf("Searching in NULL input: %s\n", result5 ? result5 : "NULL");

    return (0);
}
*/
