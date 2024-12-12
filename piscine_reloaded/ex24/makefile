# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sbruck <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/19 15:33:58 by sbruck            #+#    #+#              #
#    Updated: 2024/10/19 15:34:02 by sbruck           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = gcc
C_FLAGS = -Wall -Wextra -Werror
SRC_DIR = srcs
INC_DIR = includes

SRC_LIST = $(SRC_DIR)/ft_putchar.c \
           $(SRC_DIR)/ft_putstr.c  \
           $(SRC_DIR)/ft_strcmp.c  \
           $(SRC_DIR)/ft_strlen.c  \
           $(SRC_DIR)/ft_swap.c

OBJ_LIST = $(SRC_LIST:.c=.o)

all: $(NAME)

$(NAME): $(OBJ_LIST)
	ar rcs $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(C_FLAGS) -I $(INCDIR) -c $< -o $@

clean:
	rm -f $(OBJ_LIST)
	
fclean: clean
	rm -f $(NAME)
	
re: fclean all
