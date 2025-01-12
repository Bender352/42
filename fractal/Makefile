CC = cc
FLAGS = -Wall -Werror -Wextra -g 
MLX = -lmlx -framework OpenGl -framework AppKit
MLX_FLAGS = -Llib/minilibx-linux -lmlx_Linux -lXext -lX11
MINIMLXLIB = lib/minilibx-linux/libmlx_linux.a
FTPRINTF = -Llib/ftprintf -lftprintf
LIBFT = -Llib/libft -lft
#SRC = test_window.c
SRC = 	render.c \
		init.c \
		math_utils.c \
		fractal.c \
		events.c \
		test_window.c
OBJ = $(SRC:.c=.o)
NAME = fractol

all : $(NAME)

clean :
	@make clean -C lib/ftprintf
	@make clean -C lib/libft
	@rm -f $(OBJ)

fclean :
	@make fclean -C lib/ftprintf
	@make fclean -C lib/libft
	@rm -f $(NAME)

re :
	make fclean
	make clean
	make

$(NAME): $(OBJ)
	@make -C lib/ftprintf
	@make -C lib/libft
	$(CC) $(OBJ) $(MLX_FLAGS) $(FTPRINTF) $(LIBFT) -o $(NAME)

%.o: %.c
	@$(CC) -Wall -Wextra -Werror -I/usr/include -Ilib/minilibx -Ilib/ftprintf -g -c $< -o $@

.PHONY = all clean fclean re