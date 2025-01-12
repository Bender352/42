SRCS = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c \
       ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c \
       ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c \
       ft_calloc.c ft_strdup.c ft_toupper.c ft_tolower.c \
       ft_strchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c \
       ft_strnstr.c ft_atoi.c ft_strrchr.c ft_substr.c \
       ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c \
       ft_strmapi.c ft_striteri.c ft_putchar_fd.c \
       ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c

SRCSB = ft_lstnew_bonus.c ft_lstadd_front_bonus.c \
        ft_lstsize_bonus.c ft_lstlast_bonus.c \
        ft_lstadd_back_bonus.c ft_lstdelone_bonus.c \
        ft_lstclear_bonus.c ft_lstiter_bonus.c \
        ft_lstmap_bonus.c

SRC_OWN = ft_atodl.c

OBJS = ${SRCS:.c=.o}
OBJSB = ${SRCSB:.c=.o}
OBJ_OWN = ${SRC_OWN:.c=.o}
NAME = libft.a
LIBC = ar rcs
CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

# Creating the library with all object files (including bonus)
${NAME}: ${OBJS} ${OBJSB} ${OBJ_OWN}
	${LIBC} ${NAME} ${OBJS} ${OBJSB} ${OBJ_OWN}

all: ${NAME}

# The bonus target now builds the library and includes bonus files
bonus: ${OBJSB}
	${LIBC} ${NAME} ${OBJSB}

clean:
	${RM} ${OBJS} ${OBJSB} ${OBJ_OWN}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all bonus clean fclean re
