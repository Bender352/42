CC = gcc
FLAGS = -Wall -Werror -Wextra
SRC_PATH = 
OBJ_PATH = 
SRC_FILES = get_next_line \
			get_next_line_utils \
			main

SRC_NAME = $(addprefix $(SRC_PATH), $(addsuffix .c, $(SRC_FILES)))
OBJ_NAME = $(addprefix $(OBJ_PATH), $(addsuffix .o, $(SRC_FILES)))
OUTPUT = prog.out
NAME = library.a

all: $(NAME)

$(NAME): $(OBJ_NAME)
	ar rcs $@ $^

$(OUTPUT): $(OBJ_NAME)
	$(CC) $(FLAGS) -g -o $@ $^

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	$(CC) $(FLAGS) -g -c $< -o $@

run: $(OUTPUT)
	./$(OUTPUT)

clean:
	rm -f $(OBJ_NAME)
	rm -rf $(OBJ_PATH)

fclean: clean
	rm -f $(NAME)
	rm -f $(OUTPUT)

re: fclean all

.PHONY: all clean fclean re run