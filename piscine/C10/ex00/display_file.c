# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    display_file                                       :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sbruck <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/31 18:59:39 by sbruck            #+#    #+#              #
#    Updated: 2024/07/31 18:59:41 by sbruck           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
#include <sys/stat.h>


int		main(int argc, char **argv)
{
	if (argc == 1)
		ft_putstr("File name missing.\n", 2, 0);
	else if (argc != 2)
		ft_putstr("Too many arguments.\n", 2, 0);
	else
		ft_read(argv[1]);
}

void	ft_read(char *filepath)
{
	int	file;
	int	size;
	struct stat	file_stat;
	
	file = open(filepath, O_RDONLY);
	if (stat(filepath, &file_stat) == -1)
	{
		ft_putstr("Cannot get file stats.\n", 2, 0);
		return;
	}
	
	
	
	
	
}
