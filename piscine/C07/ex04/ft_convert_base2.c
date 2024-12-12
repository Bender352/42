/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbruck <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 13:57:48 by sbruck            #+#    #+#             */
/*   Updated: 2024/08/01 13:57:50 by sbruck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*convert_to_base(int nbr, char *base);
char	*ft_convert_base(char *nbr, char *base_from, char *base_to);
int		is_valid_base(char *base);
int		ft_atoi_base(char *nbr, char *base);

int get_base_length(char *base);
char *handle_zero_case(char *base);
int calculate_nbr_length(int nbr, int base_length);
char *allocate_result(int nbr_len, int is_negative);
/*
char	*convert_to_base(int nbr, char *base)
{
	int		base_length;
	char	*result;
	int		is_negative;
	int		nbr_len;
	int		temp_nbr;

	temp_nbr = nbr;
	base_length = 0;
	nbr_len = 0;
	temp_nbr = nbr;
	is_negative = nbr < 0;
	while (base[base_length])
		base_length++;
	if (nbr == 0)
	{
		result = (char *)malloc(2 * sizeof(char));
		if (result)
		{
			result[0] = base[0];
			result[1] = '\0';
		}
		return (result);
	}
	if (is_negative)
		nbr = -nbr;
	while (temp_nbr)
	{
		temp_nbr /= base_length;
		nbr_len++;
	}
	result = (char *)malloc(sizeof(char) * (nbr_len + 1 + is_negative));
	if (!result)
		return (NULL);
	result[nbr_len + is_negative] = '\0';
	while (nbr_len > 0)
	{
		result[--nbr_len + is_negative] = base[nbr % base_length];
		nbr /= base_length;
	}
	if (is_negative)
		result[0] = '-';
	return (result);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int	num;

	if (!is_valid_base(base_from) || !is_valid_base(base_to))
		return (NULL);
	num = ft_atoi_base(nbr, base_from);
	return (convert_to_base(num, base_to));
}
*/
// Function to handle the case where the number is zero

#include <stdlib.h>

// Function to calculate the length of a string
int get_base_length(char *base) {
    int base_length;
    base_length = 0;
    while (base[base_length]) {
        base_length++;
    }
    return base_length;
}

// Function to handle the zero case
char *handle_zero_case(char *base) {
    char *result;
    result = (char *)malloc(2 * sizeof(char));
    if (result) {
        result[0] = base[0];
        result[1] = '\0';
    }
    return result;
}

// Function to calculate the number of digits needed
int calculate_nbr_length(int nbr, int base_length) {
    int nbr_len;
    nbr_len = 0;
    while (nbr) {
        nbr /= base_length;
        nbr_len++;
    }
    return nbr_len;
}

// Function to allocate memory for the result
char *allocate_result(int nbr_len, int is_negative) {
    char *result;
    result = (char *)malloc(sizeof(char) * (nbr_len + 1 + is_negative));
    return result;
}

// Function to convert number to base and store in result
void convert_nbr_to_base(char *result, int nbr, char *base, int base_length, int nbr_len, int is_negative) {
    while (nbr_len > 0) {
        result[--nbr_len + is_negative] = base[nbr % base_length];
        nbr /= base_length;
    }
    if (is_negative) {
        result[0] = '-';
    }
}

// Main function to convert number to base
char *convert_to_base(int nbr, char *base) {
    int base_length;
    int is_negative;
    int nbr_len;
    char *result;

    base_length = get_base_length(base);
    if (nbr == 0) {
        return handle_zero_case(base);
    }

    is_negative = nbr < 0;
    if (is_negative) {
        nbr = -nbr;
    }

    nbr_len = calculate_nbr_length(nbr, base_length);
    result = allocate_result(nbr_len, is_negative);
    if (!result) {
        return NULL;
    }

    result[nbr_len + is_negative] = '\0';
    convert_nbr_to_base(result, nbr, base, base_length, nbr_len, is_negative);

    return result;
}

#include <stdio.h>

int	main(void)
{
	char	*nbr;
	char	*base_from;
	char	*base_to;
	char	*converted;

	nbr = "   -1a7";
	base_from = "0123456789abcdef";
	base_to = "01";
	converted = ft_convert_base(nbr, base_from, base_to);
	if (converted)
	{
		printf("Converted: %s\n", converted);
		free(converted); // Don't forget to free the allocated memory
	}
	else
	{
		printf("Conversion error: invalid base or input\n");
	}
	return (0);
}
