CC = cc
FLAGS = -Werror -Wextra -Wall

SRC_SERVER = server.c
SRC_CLIENT = client.c

SRC_SERVER_BONUS = server_bonus.c
SRC_CLIENT_BONUS = client_bonus.c

DIR_LIBFT = libft/
DIR_PRINTF = printf/

OBJ_CLIENT = $(SRC_CLIENT):.o
OBJ_SERVER = $(SRC_SERVER):.o
OBJ_CLIENT_BONUS = $(SRC_CLIENT_BONUS):.o
OBJ_SERVER_BONUS = $(SRC_SERVER_BONUS):.o

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

all: client server client_bonus server_bonus

m : client server

b : client_bonus server_bonus

lib_libft :
	@make -C $(DIR_LIBFT)

lib_printf :
	@make -C $(DIR_PRINTF)

client: $(OBJ_CLIENT) lib_libft lib_printf
	$(CC) $(FLAGS) $(OBJ_CLIENT) $(DIR_LIBFT)libft.a $(DIR_PRINTF)printf.a -o client.out

server: $(OBJ_SERVER) lib_libft lib_printf
	$(CC) $(FLAGS) $(OBJ_SERVER) $(DIR_LIBFT)libft.a $(DIR_PRINTF)printf.a -o server.out

client_bonus: $(OBJ_CLIENT_BONUS) lib_libft lib_printf
	$(CC) $(FLAGS) $(OBJ_CLIENT_BONUS) $(DIR_LIBFT)libft.a $(DIR_PRINTF)printf.a -o client_bonus.out

server_bonus: $(OBJ_SERVER_BONUS) lib_libft lib_printf
	$(CC) $(FLAGS) $(OBJ_SERVER_BONUS) $(DIR_LIBFT)libft.a $(DIR_PRINTF)printf.a -o server_bonus.out

clean :
	@rm -r client.o
	@rm -r server.o
	@rm -r client_bonus.o
	@rm -r server_bonus.o

fclean :
	@rm -r client.out
	@rm -r server.out
	@rm -r client_bonus.out
	@rm -r server_bonus.out

re :
	@make clean
	@make fclean
	@make all
	
.PHONY : clean fclean all re m b
