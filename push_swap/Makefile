CC = cc
FLAGS = -Wall -Werror -Wextra
SRC_PATH = /src/
OBJ_PATH = /obj/
SRC_FILES = main
SRC = $(appprefix $(SRC_PATH), $(addsuffix .c, $(SRC_FILES)))
OBJ = $(appprefix $(OBJ_PATH), $(addsuffix .o, $(SRC_FILES)))
OUTPUT = prog.out
NAME = library.a

all : $(NAME)

clean :
	@rm -rf obj

fclean :
	@rm -f $(NAME)
	
re:
	@make clean
	@make fclean
	@make all

$(NAME) :	$(OBJ)
	ar rcs $@ $^

$(OBJ_PATH)%.o :	$(SRC_PATH)%.c
	@mkdir -p obj
	$(CC) $(FLAGS) -c $< -o $@


.PHONY : all clean fclean re
