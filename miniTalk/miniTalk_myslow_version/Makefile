CC = cc
FLAGS = -Werror -Wextra -Wall

NAME = server

SRC_SERVER = server.c
SRC_CLIENT = client.c

SRC_SERVER_BONUS = server_bonus.c
SRC_CLIENT_BONUS = client_bonus.c

DIR_LIBFT = libft/
DIR_PRINTF = ft_printf/

OBJ_CLIENT = $(SRC_CLIENT:.c=.o)
OBJ_SERVER = $(SRC_SERVER:.c=.o)
OBJ_CLIENT_BONUS = $(SRC_CLIENT_BONUS:.c=.o)
OBJ_SERVER_BONUS = $(SRC_SERVER_BONUS:.c=.o)

CLIENT=client
LIBFT = $(DIR_LIBFT)libft.a
%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

all: $(NAME) 

$(NAME): $(LIBFT) lib_printf $(CLIENT) server client_bonus server_bonus 

m : client server

b : client_bonus server_bonus

$(LIBFT) :
	make -C $(DIR_LIBFT)

lib_printf :
	make -C $(DIR_PRINTF)

$(CLIENT): $(OBJ_CLIENT) 
	$(CC) $(FLAGS) $(OBJ_CLIENT) $(DIR_LIBFT)libft.a $(DIR_PRINTF)printf.a -o $(CLIENT)

server: $(OBJ_SERVER) 
	$(CC) $(FLAGS) $(OBJ_SERVER) $(DIR_LIBFT)libft.a $(DIR_PRINTF)printf.a -o server

client_bonus: $(OBJ_CLIENT_BONUS) 
	$(CC) $(FLAGS) $(OBJ_CLIENT_BONUS) $(DIR_LIBFT)libft.a $(DIR_PRINTF)printf.a -o client_bonus

server_bonus: $(OBJ_SERVER_BONUS) 
	$(CC) $(FLAGS) $(OBJ_SERVER_BONUS) $(DIR_LIBFT)libft.a $(DIR_PRINTF)printf.a -o server_bonus

clean :
	@rm -f client.o
	@rm -f server.o
	@rm -f client_bonus.o
	@rm -f server_bonus.o
	@make clean -C $(DIR_LIBFT)
	@make clean -C $(DIR_PRINTF)
	clear

fclean :
	@rm -f client
	@rm -f server
	@rm -f client_bonus
	@rm -f server_bonus
	@make fclean -C $(DIR_LIBFT)
	@make fclean -C $(DIR_PRINTF)
	clear

re :
	@make clean
	@make fclean
	make all
	
.PHONY : clean fclean all re m b
