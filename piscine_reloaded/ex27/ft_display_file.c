/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbruck <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 18:12:46 by sbruck            #+#    #+#             */
/*   Updated: 2024/10/19 19:10:04 by sbruck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

void	displ_file(int fd)
{
	char	buffer;

	while (read(fd, &buffer, 1) != 0)
		write (1, &buffer, 1);
}
/*
int	main(int arc, char **argv)
{
	int	fd;
	
	if (arc <=1)
		return (0);
	fd = open(argv[1], O_RDONLY);
	displ_file(fd);
	close(fd);
	return (0);
}
*/
