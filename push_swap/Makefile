CC = gcc
FLAGS = -Wall -Werror -Wextra
SRC_PATH = ./src/
OBJ_PATH = ./obj/
SRC_FILES = fill_stack \
            ft_split \
            new_node \
            push_swap \
			stack_handling \
			free_stuff

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
	mkdir -p $(OBJ_PATH)
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