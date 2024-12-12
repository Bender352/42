# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    libft_creator.sh                                   :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sbruck <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/29 21:11:06 by sbruck            #+#    #+#              #
#    Updated: 2024/07/29 21:11:08 by sbruck           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
#!/bin/bash
gcc -Wall -Wextra -Werror -c *.c
ar rc libft.a *.o
ranlib libft.a
rm *.o
