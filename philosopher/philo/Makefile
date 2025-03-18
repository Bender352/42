CC = CC
FLAGS = -Werror -Wall -Wextra -g -pthreadman 
SRC_PATH_MANDATORY = ./src
OBJ_PAHT_MANDATORY = ./obj
SRC_FILES_MANADTORY = main \
					  philosopher
SRC_NAME_MANDATORY = $(addprefix $(SRC_PATH_MANDATORY), $(addsuffix .c, $(SRC_FILES_MANADTORY)))
OBJ_NAME_MANDATORY = $(addprefix $(OBJ_PAHT_MANDATORY), $(addsuffix .o, $(SRC_FILES_MANADTORY)))
OUTPUT = philo
NAME = library.a

all: $(OUTPUT)

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

rec: fclean all
	clear

.PHONY: all clean fclean re rec run clear