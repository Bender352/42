CC = gcc
FLAGS = -Wall -Werror -Wextra -g
SRC = get_next_line.c \
	  get_next_line_utils.c \
	  main.c
OBJ_DIR = utilities/obj
OBJ = $(OBJ_DIR)/get_next_line.o \
	  $(OBJ_DIR)/get_next_line_utils.o \
	  $(OBJ_DIR)/main.o
OUTPUT = test.out

all : $(OUTPUT)

$(OUTPUT) : $(OBJ)
	$(CC) $(FLAGS) -g $(OBJ) -o $(OUTPUT)

clean : 
	rm -f $(OBJ)
	rm -fr $(OBJ_DIR)

fclean : clean
	rm -f $(OUTPUT)

run : all
	clear
	./$(OUTPUT)

test :
	make fclean
	clear
	$(OUTPUT)

$(OBJ_DIR)/%.o : %.c
	mkdir -p $(OBJ_DIR)
	$(CC) $(FLAGS) -c $< -o $@

.PHONY : fclean all clean test
