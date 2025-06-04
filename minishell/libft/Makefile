Name = libftprintf.a
CC = gcc
RM = rm -rf
CFlags = -Wall -Werror -Wextra
SourceC = ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c \
	  ft_isascii.c ft_isdigit.c ft_isprint.c ft_memchr.c \
	  ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c \
	  ft_strchr.c ft_strlcat.c ft_strlcpy.c ft_strlen.c \
	  ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_tolower.c \
	  ft_toupper.c ft_calloc.c ft_strdup.c ft_substr.c \
	  ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c \
	  ft_strmapi.c ft_striteri.c ft_putchar_fd.c \
	  ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
	  ft_printf.c \
	  ft_print_char.c \
	  ft_check_conversion.c \
	  ft_print_str.c \
	  ft_convert_toascii.c \
	  ft_print_base10.c \
	  ft_uitoa.c \
	  ft_print_hex.c \
	  ft_print_uint.c \
	  ft_printf_ptrhex.c

OBJS = $(SourceC:.c=.o)
%o:%c
all: $(Name)

$(Name): $(OBJS)
	@ar rc $(Name) $(OBJS)

clean:
	@$(RM) $(OBJS)

%.o: %.c
	@$(CC) $(CFlags) -c $< -o $@
fclean: clean
	@$(RM) $(Name)

re: fclean all

.PHONY: all clean fclean re
