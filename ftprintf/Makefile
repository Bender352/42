SRC_FILES = ft_printf \
	  ft_str_len \
	  ft_put_char \
	  ft_base_hex \
	  ft_base_num \
	  ft_print_str \
	  ft_ptr_add \
	  ft_handle_num

SRC_PATH = 
OBJ_PATH =
SRC = $(addsuffix .c, $(SRC_FILES))
OBJ = $(addsuffix .o, $(SRC_FILES))
CC = gcc
FLAGS = -Wall -Werror -Wextra
OUTPUT = prog.out
NAME = libftprintf.a

all :	$(NAME)

clean :
	@rm -f $(OBJ)

fclean :
	@rm -f $(NAME)

re :
	@make fclean 
	@make all

run :	$(OBJ)
	@$(CC) $(FLAGS) $(OBJ) -o $(OUTPUT)
	@clear 
	@make fclean 
	@rm -f $(OUTPUT)
	@make
	@clear 
	@./$(OUTPUT)

$(NAME) : $(OBJ)
	@ar rcs $(NAME) $^

$(OBJ_PATH)%.o :	$(SRC_PATH)%.c
	@$(CC) $(FLAGS) -c $< -o $@


.PHONY : all clean fclean re makerun
