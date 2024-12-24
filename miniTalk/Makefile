CC = cc
FLAGS = -Werror -Wextra -Wall
SRC = server.c \
	  client.c
OBJ = %.c : %.o
	$(CC) $(FLAGS) -g -c $< -o $@

all : $(OBJ)
	$(CC) $(FLAGS) -g $(OBJ) -o client.out

clean :
	rm -r client.o
	rm -r server.o
	rm -r client.out
	rm -r server.out
fclean :

.PHONY : clean fclean all
