/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knjaloun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 15:17:54 by knjaloun          #+#    #+#             */
/*   Updated: 2024/10/30 13:10:47 by knjaloun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_write_specialcase(int n, int fd)
{
	if (n == 0)
	{
		write(fd, "0", 1);
		return (1);
	}
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return (1);
	}
	return (0);
}

static int	ft_getnumlen(int n)
{
	int	len;

	len = 0;
	if (n == 0)
	{
		return (1);
	}
	if (n < 0)
		len++;
	while (n != 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

void	ft_putnbr_fd(int n, int fd)
{
	char	iasstr[12];
	size_t	index;

	index = ft_getnumlen(n);
	iasstr[index] = '\0';
	index--;
	if (ft_write_specialcase(n, fd) == 1)
		return ;
	if (n < 0)
	{
		iasstr[0] = '-';
		n *= -1;
	}
	while (n != 0)
	{
		iasstr[index] = (n % 10) + '0';
		index --;
		n = n / 10;
	}
	write(fd, iasstr, ft_strlen(iasstr));
}
