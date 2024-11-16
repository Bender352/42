SRC_FILES = ft_printf \
	  ft_str_len \
	  ft_put_char \
	  ft_base_hex \
	  ft_base_num \
	  ft_print_str \
	  ft_ptr_add \
	  ft_handle_num

SRC_PATH = src/
OBJ_PATH = obj/
SRC = $(addprefix $(SRC_PATH), $(addsuffix .c, $(SRC_FILES)))
OBJ = $(addprefix $(OBJ_PATH), $(addsuffix .o, $(SRC_FILES)))
CC = gcc
FLAGS = -Wall -Werror -Wextra
OUTPUT = prog.out
NAME = libftprintf.a

all :	$(NAME)

clean :
	rm -f $(OBJ)

fclean :
	rm -f $(OBJ)
	rm -f $(OUTPUT)

re :
	fclean all

run :	$(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(OUTPUT)
	clear 
	make fclean 
	make
	clear 
	./$(OUTPUT)

$(NAME) : $(OBJ)
	ar rcs $(NAME) $^

$(OBJ_PATH)%.o :	$(SRC_PATH)%.c
	$(CC) $(FLAGS) -c $< -o $@


.PHONY : all clean fclean re makerun

